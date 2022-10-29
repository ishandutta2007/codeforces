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

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            if(sign == 1){
                Set(Zero, q);
            }
            else {
                Set(One, q);
            }
            H(q);
        }
    }
}