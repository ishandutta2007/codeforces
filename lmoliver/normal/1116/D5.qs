namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
		CNOT(qs[1],qs[2]);

		(ControlledOnInt(0,H))([qs[2]],qs[0]);
		(ControlledOnInt(0,H))([qs[2]],qs[1]);

		CCNOT(qs[2],qs[0],qs[1]);
		CNOT(qs[2],qs[1]);
		Controlled H([qs[2]],qs[0]);
		
		CNOT(qs[1],qs[2]);
    }
}