namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
		using (q = Qubit[1])
		{
			unitary(q[0]);
			X(q[0]);
			unitary(q[0]);
			if (M(q[0]) == One) { set res = 1; }
			ResetAll(q);
		}
		return res;
	}
}