namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
		using (q = Qubit[2])
		{
			X(q[0]); X(q[1]);
			unitary(q[0..1]);
			if (M(q[0]) == Zero)
			{
				set res = 2;
			}
			elif (M(q[1]) == Zero)
			{
				set res = 1;
			}
			else
			{
				ResetAll(q);
				X(q[0]);
				unitary(q[0..1]);
				if (M(q[0]) == Zero)
				{
					set res = 3;
				}
			}
			ResetAll(q);
		}
		return res;
	}
}