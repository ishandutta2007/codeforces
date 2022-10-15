namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

	operation Set(x : Qubit, y : Result) : Unit {
		if (M(x) != y) {
			X(x);
		}
	}

    operation Solve (qs : Qubit[]) : Int {
        body (...) {
			let n = Length(qs);
			mutable tot = 0;
			for (i in 0..n - 1) {
				if (M(qs[i]) == One) {
					set tot = tot + 1;
				}
			}
			if (tot == n || tot == 0) {
				return 0;
			}
			else {
				return 1;
			}
        }
    }

	
}