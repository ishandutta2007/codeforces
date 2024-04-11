namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set(desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if(desired != current){
                X(q1);
            }
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable s = true;
            using(q = Qubit[N]){
                using(p = Qubit[1]){
                    for(i in 0..N-1){
                        Set(Zero, q[i]);
                        H(q[i]);
                    }
                    Set(One, p[0]);
                    H(p[0]);
                    Uf(q,p[0]);
                    for(i in 0..N-1){
                        H(q[i]);
                    }
                    for(i in 0..N-1){
                        if(M(q[i]) == One){
                            set s = false;
                        }
                    }
                    for(i in 0..N-1){
                        Set(Zero, q[i]);
                    }
                    Set(Zero, p[0]);
                }
            }
            return s;
        }
    }
}