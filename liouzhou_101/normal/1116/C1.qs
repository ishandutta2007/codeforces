namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
			mutable n = Length(x);
			using (p = Qubit[n-1])
			{
				for (i in 0..n-2)
				{
					CNOT(x[i], p[i]);
					CNOT(x[i+1], p[i]);
				}
				(Controlled X)(p, y);
				for (i in 0..n-2)
				{
					CNOT(x[i], p[i]);
					CNOT(x[i+1], p[i]);
				}
			}
        }
        adjoint auto;
    }
}