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

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let n = Length(qs);
            Set(Zero, qs[0]);
            H(qs[0]);
            for(i in 1..n-1){            
                Set(Zero, qs[i]);
                CNOT(qs[0], qs[i]);
            }
        }
    }
}