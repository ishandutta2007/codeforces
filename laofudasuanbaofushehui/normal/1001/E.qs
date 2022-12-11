namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            if (M(qs[1])==Zero) {
            	if (M(qs[0])==Zero) {
            		return 0;
            	} else {
            		return 1;
            	}
            } else {
            	if (M(qs[0])==Zero) {
            		return 2;
            	} else {
            		return 3;
            	}
            }
        }
    }
}