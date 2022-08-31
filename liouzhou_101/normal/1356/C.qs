namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (qs : Qubit[]) : Unit {
		mutable res = One;
		for (i in 1..100)
		{
			if (res == One)
			{
				ResetAll(qs);
				H(qs[0]);
				H(qs[1]);
				using (p = Qubit[1])
				{
					Controlled X(qs[0..1], p[0]);
					set res = M(p[0]);
					if (res == One)
					{
						X(p[0]);
					}
				}
			}
		}
		X(qs[0]);
		X(qs[1]);
	}
}