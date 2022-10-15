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
			Ry(0.25 * PI(), q);
		//	DumpMachine("q.txt");
			let ans = M(q);
			if (ans == One) {return 1;}
			return 0;
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