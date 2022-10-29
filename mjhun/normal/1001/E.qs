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
            CNOT(q0,q1);
            H(q0);
            mutable res = 0;
            if(M(q0) == One){
                set res = res + 1;
            }
            if(M(q1) == One){
                set res = res + 2;
            }
            return res;
        }
    }
}