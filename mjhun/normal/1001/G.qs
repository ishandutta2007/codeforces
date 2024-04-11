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

    operation Solve (x : Qubit[], y : Qubit, k : Int) : ()
    {
        body
        {
            CNOT(x[k],y);
        }
    }
}