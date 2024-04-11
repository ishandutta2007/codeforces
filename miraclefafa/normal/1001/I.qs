namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable cst=1;
            using (qs=Qubit[N+1]) {
                for (i in 0..N-1) {
                    Set(Zero, qs[i]);
                }
                Set(One,qs[N]);
                for (i in 0..N) {
                    H(qs[i]);
                }
                Uf(qs[0..N-1],qs[N]);
                for (i in 0..N) {
                    H(qs[i]);
                }
                for (i in 0..N-1) {
                    let c=M(qs[i]);
                    if (c==One) {
                        set cst=0;
                    }
                }
                for (i in 0..N) {
                    Set(Zero, qs[i]);
                }
            }
            if (cst==1) {
                return true;
            } else {
                return false;
            }
        }
    }
}