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
            mutable r = 0;
            let q0 = qs[0];
            let q1 = qs[1];
            H(q0);
            CNOT(q0,q1);
            if(M(q1) == Zero){
                set r = r+1;
            }
            H(q0);
            if(M(q0) == Zero){
                set r = r+2;
            }
            return r;
        }
    }
}