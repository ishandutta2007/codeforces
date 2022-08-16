namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Increment(q: Qubit[]) : Unit is Adj+Ctl {
		body (...)
		{
			mutable n = Length(q);
			if (n == 1)
			{
				X(q[0]);
			}
			else
			{
				for (i in (n-2)..(-1)..0)
				{
					Controlled X(q[0..i], q[i+1]);
				}
				X(q[0]);
			}
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}

	operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
		body (...)
		{
			mutable n = Length(inputs);
			using (p = Qubit[4])
			{
				for (i in 0..n-1)
				{
					Controlled Increment(inputs[i..i], p[0..3]);
				}
				for (k in 0..3)
				{
					if (n/2/(1<<<k)%2 == 0) { X(p[k]); }
				}
				Controlled X(p[0..3], output);
				for (k in 0..3)
				{
					if (n/2/(1<<<k)%2 == 0) { X(p[k]); }
				}
				for (i in 0..n-1)
				{
					Controlled Adjoint Increment(inputs[i..i], p[0..3]);
				}
			}
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}
}