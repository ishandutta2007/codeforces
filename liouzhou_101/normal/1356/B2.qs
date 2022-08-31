namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Increment (register : LittleEndian) : Unit is Adj+Ctl {
		body (...)
		{
			mutable n = Length(register!);
			if (n == 1)
			{
				X(register![0]);
			}
			else
			{
				for (i in (n-2)..(-1)..0)
				{
					Controlled X(register![0..i], register![i+1]);
				}
				X(register![0]);
			}
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}

	operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
		body (...)
		{
			Adjoint Increment(register);
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}
}