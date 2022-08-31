namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	
	operation MyAddMod3(x : Qubit, p0 : Qubit, p1 : Qubit) : Unit
	{
		body(...)
		{
			CCNOT(x, p1, p0);
			CCNOT(x, p0, p1);
			CCNOT(x, p1, p0);
			CNOT(x, p1);
			CCNOT(x, p1, p0);
			CNOT(x, p1);
		}
		adjoint auto;
	}

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
			mutable n = Length(x);
			using (p = Qubit[2])
			{
				for (i in 0..n-1)
				{
					MyAddMod3(x[i], p[0], p[1]);
				}
				X(p[0]);
				X(p[1]);
				CCNOT(p[0], p[1], y);
				X(p[0]);
				X(p[1]);
				for (i in 0..n-1)
				{
					MyAddMod3(x[i], p[0], p[1]);
					MyAddMod3(x[i], p[0], p[1]);
				}
			}
        }
        adjoint auto;
    }
}