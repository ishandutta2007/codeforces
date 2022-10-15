namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

	operation Set(x : Qubit, y : Result) : Unit {
		if (M(x) != y) {
			X(x);
		}
	}

    operation Solve (x : Qubit[], y : Bool[]) : Unit {
        body (...) {
			let n = Length(x);
			H(x[0]);
            for (i in 1..n-1) {
				if (y[i]) {
					CNOT(x[0], x[i]);
				}
			}
        }
        adjoint auto;
    }
}