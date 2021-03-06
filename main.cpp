//Main Test File for Langevin Simuator

#include "langsim.hpp" //Single File Interface

int main()
{
	
	Modes::SetModeCode(7); //Declare that the working mode is 15
	
	//0. Specify HomePath(that should exist) → Optional
	HomePath("/mnt/m/code/FCS/Results/");

	//1. Create NewSession(session_name, box_mode) box_modes → "singlebox"/"multibox"
	NewSession("Test", "singlebox");

	//2. Create Simulation Clock Object → SimClock(MaxSteps, Step_Size)
	SimClock simclock(1e7, 1e-3);

	//3. Create Laser Object → (pulse interval, char, decy time)
	Laser laser("always-on"); //Pulse Every 10 dt, char decay time is 5 dt

	//4. Create Veff Object → Veff(radius, structure_factor)
	Veff veff(500.0, 2);

	//5. Create Box Object → LangevinBox(Rho, Part_no, FrameExports, simclock, laser, veff)
	int write_frames = 1000;
	double Rho = 1e-9;
	int Part_no = 100;
	
	gl::do_pos_plots = true;


	//Units(double Sigma, double Temp, double Viscosity)
	Units units;
	units.set_scale_STE(1e-9, 273.16, CONST_WATER_VISCOSITY);

	LangevinBox box(Rho, Part_no, write_frames, simclock, laser, veff, units);

	//6. Evolve Box → Run Box
	box.Evolve();


///////////////////// Test Features --------------------------><


	/*
	  • Check if the extension has a dot in the beginning
	  • Check if the Gpaths provided obey corresponding operationg system format
	  • Check if the passed ModeCode Matches the compiled ModeCode
	*/
}


