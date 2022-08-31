namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        X(qs[0]);
		X(qs[1]);
		mutable m = One;
		for (i in 0..100)
		{
			using (p = Qubit[1])
			{
				if (m == One)
				{
					X(qs[0]);
					X(qs[1]);
					H(qs[0]);
					H(qs[1]);
					CCNOT(qs[0], qs[1], p[0]);
					set m = M(p[0]);
				}
				ResetAll(p);
			}
		}
    }
}