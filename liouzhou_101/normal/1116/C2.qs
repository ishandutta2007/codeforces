namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
			mutable n = Length(x);
			using (p = Qubit[n/2])
			{
				for (tt in 1..n/2)
				{
					mutable t = n-tt;
					using (q = Qubit[n-t])
					{
						for (i in 0..n-t-1) { X(q[i]); }
						for (i in t..n-1)
						{
							CNOT(x[i-t], q[i-t]);
							CNOT(x[i], q[i-t]);
						}
						(Controlled X)(q, p[tt-1]);
						for (i in t..n-1)
						{
							CNOT(x[i-t], q[i-t]);
							CNOT(x[i], q[i-t]);
						}
						for (i in 0..n-t-1) { X(q[i]); }
					}
				}
				for (i in 0..n/2-1) { X(p[i]); }
				(Controlled X)(p, y);
				for (i in 0..n/2-1) { X(p[i]); }
				X(y);
				for (tt in 1..n/2)
				{
					mutable t = n-tt;
					using (q = Qubit[n-t])
					{
						for (i in 0..n-t-1) { X(q[i]); }
						for (i in t..n-1)
						{
							CNOT(x[i-t], q[i-t]);
							CNOT(x[i], q[i-t]);
						}
						(Controlled X)(q, p[tt-1]);
						for (i in t..n-1)
						{
							CNOT(x[i-t], q[i-t]);
							CNOT(x[i], q[i-t]);
						}
						for (i in 0..n-t-1) { X(q[i]); }
					}
				}
			}
        }
        adjoint auto;
    }
}