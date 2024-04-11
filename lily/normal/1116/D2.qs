namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Math;
	
    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        for (i in 1..n-1) {
			for (j in 0..i - 1) {
				Controlled Ry([qs[i]], (5.0/17.0 * PI(), qs[j]));
			}
        }
    }
}