namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
		mutable pi = 3.1415926535897932384626;
		using (q = Qubit[2])
		{
			H(q[0]); CNOT(q[0], q[1]);
			Controlled unitary(q[0..0], (2.0*pi, q[1]));
			CNOT(q[0], q[1]); H(q[0]);
			if (M(q[0]) == Zero) { set res = 1; }
			ResetAll(q);
		}
		return res;
	}
}