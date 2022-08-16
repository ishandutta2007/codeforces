namespace Solution {
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable ret = 0;
		using (p = Qubit[2])
		{
			H(p[0]);
			CNOT(p[0], p[1]);
			Controlled unitary(p[0..0], p[1]);
			CNOT(p[0], p[1]);
			H(p[0]);
			if (M(p[0]) == Zero)
			{
				set ret = 1;
			}
			else
			{
				set ret = 0;
			}
			ResetAll(p);
		}
		return ret;
	}
}