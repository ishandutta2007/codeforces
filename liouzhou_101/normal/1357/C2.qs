namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (qs : Qubit[], parity : Int) : Unit {
		mutable flag = 0;
		for (go in 1..100)
		{
			if (flag == 0)
			{
				ResetAll(qs);
				mutable n = Length(qs);
				for (i in 0..n-1) { H(qs[i]); }
				using (p = Qubit[1])
				{
					for (i in 0..n-1) { CNOT(qs[i], p[0]); }
					mutable m = 0;
					if (M(p[0]) == One) { set m = 1; }
					if (m == parity) { set flag = 1; }
					ResetAll(p);
				}
			}
		}
	}
}