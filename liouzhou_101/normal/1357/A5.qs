namespace Solution {
	open Microsoft.Quantum.Arithmetic;
	open Microsoft.Quantum.Intrinsic;

	operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {

		mutable pi = 3.1415926535897932384626;
		mutable times = -1;
		mutable cur = 0.0;
		let eps = 1.57;
		for (i in 1..200)
		{
			set cur = cur+theta;
			if (cur > 2.0*pi) { set cur = cur-2.0*pi; }
			mutable tmp = cur-pi;
			if (tmp < 0.0) { set tmp = -tmp; }
			if ((times == -1) and (tmp < eps)) { set times = i; }
		}

		mutable c0 = 0;
		mutable c1 = 0;

		using (p = Qubit[1])
		{
			for (test in 1..50)
			{
				if (c1 == 0)
				{
					for (go in 1..times) { unitary(p[0]); }
					if (M(p[0]) == Zero) { set c0 = c0+1; } else { set c1 = c1+1; X(p[0]); }
				}
			}
		}
		
		if (c1 == 0) { return 0; } else { return 1; }
	}
}