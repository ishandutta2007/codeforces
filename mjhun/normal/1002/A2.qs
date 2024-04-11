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

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            let N = Length(qs);
            mutable t = -1;
            for(i in 0..N-1){
                if(bits[i]){
                    if(t < 0){
                        H(qs[i]);
                        set t = i;
                    }
                    else {
                        CNOT(qs[t],qs[i]);
                    }
                }
            }
        }
    }
}