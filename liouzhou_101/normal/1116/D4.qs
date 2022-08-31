namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	
    operation Solve (qs : Qubit[]) : Unit {
		mutable n = Length(qs);
		mutable m = 1;
		for (i in 0..n-1)
		{
			set m = m*2;
		}
		for (i in 0..m/2-1)
		{
			mutable x = i;
			for (k in 0..n-2)
			{
				if (x%2 == 0) { X(qs[0]); }
				CNOT(qs[0], qs[k+1]);
				if (x%2 == 0) { X(qs[0]); }
				set x = x/2;
			}
			(Controlled H)(qs[1..n-1], qs[0]);
			set x = i;
			for (k in 0..n-2)
			{
				if (x%2 == 0) { X(qs[0]); }
				CNOT(qs[0], qs[k+1]);
				if (x%2 == 0) { X(qs[0]); }
				set x = x/2;
			}
		}
		for (i in 0..n/2-1) { SWAP(qs[i], qs[n-i-1]); }
		X(qs[0]);
		for (i in 1..n-1)
		{
			(Controlled X)([qs[0]]+qs[i+1..n-1], qs[i]);
		}
		X(qs[0]);
		for (i in 1..n-1)
		{
			for (j in i+1..n-1) { X(qs[j]); }
			(Controlled X)([qs[0]]+qs[i+1..n-1], qs[i]);
			for (j in i+1..n-1) { X(qs[j]); }
		}
		X(qs[0]);
		for (i in 0..n/2-1) { SWAP(qs[i], qs[n-i-1]); }
    }
}