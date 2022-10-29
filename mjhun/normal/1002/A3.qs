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

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let N = Length(qs);
            for(i in 0..N-1){
                if(bits0[i]){
                    X(qs[i]);
                }
            }
            mutable t = -1;
            for(i in 0..N-1){
                if(bits0[i] != bits1[i]){
                    if(t < 0){
                        if(!bits0[i]){
                            H(qs[i]);
                            set t = i;
                        }
                        else {
                            X(qs[i]);
                            H(qs[i]);
                            set t = i;
                        }
                    }
                    else {
                        if(!bits0[t]){
                            CNOT(qs[t],qs[i]);
                        }
                        else {
                            X(qs[i]);
                            CNOT(qs[t],qs[i]);
                        }
                    }
                }
            }
        }
    }
}