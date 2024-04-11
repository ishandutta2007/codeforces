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
			for (i in 0..n - 1) {
				if (M(qs[i]) == One) {
					return 1;
				}
			}
			return 0;
        }
    }

	
}