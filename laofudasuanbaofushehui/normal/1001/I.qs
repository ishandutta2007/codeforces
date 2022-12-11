namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
	operation Set (desired: Result, q1:Qubit) : ()    
    {
        body
        {
            //qubit
            let current = M(q1);
            if (desired != current)
            {
                //
                X(q1);
            }
        }
    }
    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
        	mutable rt=true;
            using (x=Qubit[N]) {
            	using (y=Qubit[1]) {
            		Set(One,y[0]);
            		for (i in 0..N-1) {
            			Set(Zero,x[i]);
            			H(x[i]);
            		}
            		H(y[0]);
            		Uf(x,y[0]);
            		for (i in 0..N-1) {
            			H(x[i]);
            		}
            		for (i in 0..N-1) {
            			if (M(x[i])==One) {
            				set rt=false;
            			}
            		}
            		for (i in 0..N-1) {
            			Set(Zero,x[i]);
            		}
            		Set(Zero,y[0]);
            	}
            }
            return rt;
        }
    }
}