namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Increment(p: Qubit[]) : Unit is Adj+Ctl {
		body (...)
		{
			mutable n = 2;
			if (n == 1)
			{
				X(p[0]);
			}
			else
			{
				for (i in (n-2)..(-1)..0)
				{
					Controlled X(p[0..i], p[i+1]);
				}
				X(p[0]);
			}
			Controlled X(p[0..1], p[2]);
			Controlled X(p[2..2], p[0]);
			Controlled X(p[2..2], p[1]);
			X(p[0]); X(p[1]);
			Controlled X(p[0..1], p[2]);
			X(p[0]); X(p[1]);
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}

	operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
		body (...)
		{
			mutable n = Length(inputs);
			using (p = Qubit[3])
			{
				for (i in n-1..-1..0)
				{
					SWAP(p[0], p[1]);
					Controlled Increment(inputs[i..i], p[0..2]);
				}
				X(p[0]); X(p[1]);
				Controlled X(p[0..1], output);
				X(p[0]); X(p[1]);
				for (i in 0..n-1)
				{
					Controlled Adjoint Increment(inputs[i..i], p[0..2]);
					SWAP(p[0], p[1]);
				}
			}
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}
}