namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs : Qubit[]) : Int {
		CNOT(qs[2], qs[0]);
		CNOT(qs[2], qs[1]);
		CCNOT(qs[0], qs[1], qs[2]);
		
		//two-level decomposition
		
		(Controlled Rz)(qs[1..1], (PI()/3.0, qs[0]));
		(Controlled Ry)(qs[1..1], (PI()/2.0, qs[0]));
		(Controlled Rz)(qs[1..1], (PI()/2.0, qs[0]));
		R1(PI()/4.0, qs[1]);
		
		(Controlled Ry)(qs[0..0], (0.955316618124509278163857102515757754243414695010005490959*2.0, qs[1])); // sin(theta/2) = 2/sqrt(6)
		(Controlled X)(qs[0..0], qs[1]);
		
		SWAP(qs[0], qs[1]);
		CNOT(qs[1], qs[0]);
		(Controlled H)(qs[1..1], qs[0]);
		SWAP(qs[0], qs[1]);
		CNOT(qs[0], qs[1]);
		
		if (M(qs[0]) == One) { return 1; } else { return 0; }
		
		return 1;
    }
}