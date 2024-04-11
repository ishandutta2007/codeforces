namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Extensions.Diagnostics;
	open Microsoft.Quantum.Extensions.Convert;
	open Microsoft.Quantum.Extensions.Math;
	operation Rand() : Int {
		mutable ret = Zero;
		using (q = Qubit[1]) {
			H(q[0]);
			set ret = M(q[0]);
			Reset(q[0]);
		}
		if (ret == Zero) {return 0;}
		else {return 1;}
	}
    operation Solve (q : Qubit) : Int {
        body {
			mutable ans = -1;
			if (Rand() == 0) {
				H(q);
				if (M(q) == One) {set ans = 0;}
			}
			else {
				if (M(q) == One) {set ans = 1;}
			}
			return ans;
        }
    }

	operation Test () : (Int, Int, Bool) {
		let tar = Rand();
		mutable ret = 0;
		mutable ok = false;
		using (q = Qubit[1]) {
			let b = q[0];
			if (tar == 1) {H(b);}
			set ret = Solve(b);
			set ok = ret == tar;
			Reset(b);
		}
		return (tar, ret,  ok);
	}
}