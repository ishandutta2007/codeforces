namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
		mutable n = Length(qs);
		using (p = Qubit[2])
		{
			H(p[0]);
			H(p[1]);
			for (i in 0..3)
			{
				mutable x0 = i%2;
				mutable x1 = i/2;
				if (x0 == 0) { X(p[0]); }
				if (x1 == 0) { X(p[1]); }
				for (k in 0..n-1)
				{
					if (bits[i][k]) { CCNOT(p[0], p[1], qs[k]); }
				}
				if (x0 == 0) { X(p[0]); }
				if (x1 == 0) { X(p[1]); }
			}
			for (i in 0..3)
			{
				mutable x0 = i%2;
				mutable x1 = i/2;
				for (k in 0..n-1)
				{
					if (bits[i][k] == false) { X(qs[k]); }
				}
				if (x0 == 1) { (Controlled X)(qs, p[0]); }
				if (x1 == 1) { (Controlled X)(qs, p[1]); }
				for (k in 0..n-1)
				{
					if (bits[i][k] == false) { X(qs[k]); }
				}
			}
			ResetAll(p);
		}
    }
}