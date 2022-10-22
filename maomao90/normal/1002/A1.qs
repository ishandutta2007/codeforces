 namespace Solution {
        open Microsoft.Quantum.Primitive;
        open Microsoft.Quantum.Canon;
     
    	operation Set(x : Qubit, y : Result) : Unit {
    		if (M(x) != y) {
    			X(x);
    		}
    	}
     
        operation Solve (x : Qubit[]) : Unit {
            body (...) {
    			let n = Length(x);
                for (i in 0..n-1) {
    				H(x[i]);
    			}
            }
            adjoint auto;
        }
    }