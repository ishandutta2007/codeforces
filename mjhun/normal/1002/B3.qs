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

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let q0 = qs[0];
            let q1 = qs[1];
            mutable r = 0;
            H(q0);
            if(M(q0) == One){
                set r = r+2;
            }
            H(q1);
            if(M(q1) == One){
                set r = r+1;
            }
            return r;
        }
    }
}