namespace Solution {
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable ret = 0;
		using (p = Qubit[1])
		{
			H(p[0]);
			unitary(p[0]);
			H(p[0]);
			if (M(p[0]) == Zero)
			{
				set ret = 0;
			}
			else
			{
				set ret = 1;
			}
			ResetAll(p);
		}
		return ret;
	}
}