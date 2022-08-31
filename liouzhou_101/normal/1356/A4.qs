namespace Solution {
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
		mutable ret = 0;
		using (p = Qubit[2])
		{
			unitary(p[0..1]);
			if (M(p[1]) == Zero)
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