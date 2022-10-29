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

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            let q0=qs[0];
            let q1=qs[1];

            if(index == 0 || index == 2){
                Set(Zero, q0);
            }
            else {
                Set(One, q0);
            }

            if(index < 2){
                Set(Zero, q1);
            }
            else {
                Set(One, q1);
            }

            H(q0);
            CNOT(q0,q1);
        }
    }
}