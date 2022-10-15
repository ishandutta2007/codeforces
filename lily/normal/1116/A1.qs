namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Math;
	
    operation Solve (qs : Qubit[]) : Unit {
        body {
			Ry(ArcSin(Sqrt(8.0) / 3.0), qs[0]);
			X(qs[0]);
			Controlled H([qs[0]], qs[1]);
			X(qs[0]);
		//	DumpMachine("q.txt");
        }
    }

	operation Test () : Unit {
		using (q = Qubit[2]) {
			Message("Test");
			Solve(q);
			Reset(q[0]);
			Reset(q[1]);
		}
	}
}