namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        mutable n = Length(qs);
		for (i in 0..n-2)
		{
			for (j in i+1..n-1)
			{
				(Controlled H)(qs[n-i-1..n-1], qs[n-j-1]);
			}
			X(qs[n-i-1]);
		}
		for (i in 0..n-2)
		{
			X(qs[n-i-1]);
		}
    }
}