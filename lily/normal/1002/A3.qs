namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

	operation Set(x : Qubit, y : Result) : Unit {
		if (M(x) != y) {
			X(x);
		}
	}

    operation Solve (q : Qubit[], x : Bool[], y : Bool[]) : Unit {
        body (...) {
			let n = Length(q);
			mutable p = -1;
			for (i in 0..n-1) {
				if (p == -1 && x[i] != y[i]) {
					set p = i;
				}
			}
			for (i in 0..n-1) {
				if (x[i] == y[i]) {
					if (x[i]) {X(q[i]);}
				}
				else {
					if (i == p) {
						H(q[i]);
					}
					else {
						CNOT(q[p], q[i]);
						if (x[i] != x[p]) {
							X(q[i]);
						}
					}
				}
			}
        }
    }
}