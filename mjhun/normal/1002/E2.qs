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

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable r = new Int[N];
            for(i in 0..N-1){
                set r[i] = 0;
            }
            using(q = Qubit[N]){
                using(p = Qubit[1]){
                    for(i in 0..N-1){
                        Set(One, q[i]);
                    }
                    Set(Zero, p[0]);
                    Uf(q, p[0]);
                    if(M(p[0]) == One){
                        set r[0] = 1;
                    }
                    for(i in 0..N-1){
                        Set(Zero, q[i]);
                    }
                    Set(Zero, p[0]);
                }
            }
            return r;   
        }
    }
}