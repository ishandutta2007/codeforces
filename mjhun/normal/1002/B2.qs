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
            let n = Length(qs);
            mutable q = 0;
            for(i in 0..n-1){
                if(M(qs[i]) == One){
                    set q = q+1;
                }
            }
            if(q == 1){
                return 1;
            }
            return 0;
        }
    }
}