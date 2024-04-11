namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Math;
	
    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
		for (i in 1..n-1) {
			CNOT(qs[0], qs[i]);
		}
		H(qs[0]);
		for (i in 1..n-1) {
			CNOT(qs[0], qs[i]);
		}
    }
}