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

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable r = -1;
            using(p = Qubit[1]){
                Set(Zero,p[0]);
                H(p[0]);
                if(M(p[0]) == Zero){
                    H(q);
                    if(M(q) == One){
                        set r = 0;
                    }
                }
                else {
                    if(M(q) == One){
                        set r = 1;
                    }
                }
                Set(Zero,p[0]);
            }
            return r;
        }
    }
}