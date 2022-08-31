namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	
	operation Sub2 (qs : Qubit[]) : Unit
	{
		X(qs[1]);
		CNOT(qs[1], qs[2]);
		X(qs[1]);
		X(qs[1]);
	}
	
	operation Add2 (qs : Qubit[]) : Unit
	{
		CNOT(qs[1], qs[2]);
		X(qs[1]);
	}
	
	operation S24 (qs : Qubit[]) : Unit
	{
		X(qs[0]);
		CCNOT(qs[0], qs[1], qs[2]);
		CCNOT(qs[0], qs[2], qs[1]);
		CCNOT(qs[0], qs[1], qs[2]);
		X(qs[0]);
	}
	
	operation U (qs : Qubit[]) : Unit
	{
		X(qs[2]);
		(Controlled H)(qs[2..2], qs[0]);
		X(qs[2]);
		(Controlled H)(qs[2..2], qs[0]);
		(Controlled H)(qs[2..2], qs[1]);
	}
	
    operation Solve (qs : Qubit[]) : Unit {
		
		S24(qs);
		Sub2(qs);
		U(qs);
		Add2(qs);
		
    }
}