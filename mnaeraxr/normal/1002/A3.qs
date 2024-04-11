namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);

            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable pos = -1;

            for (i in 0..Length(qs) - 1){
                if (bits0[i] != bits1[i]){
                    set pos = i;
                }
            }

            if (!bits0[pos]){
                for (i in 0..Length(qs) - 1){
                    if (bits0[i]){
                        Set(One, qs[i]);
                    }
                }
            }
            else{
                for (i in 0..Length(qs) - 1){
                    if (bits1[i]){
                        Set(One, qs[i]);
                    }
                }
            }

            H(qs[pos]);

            for (i in 0..pos - 1){
                if (bits0[i] != bits1[i]){
                    CNOT(qs[pos], qs[i]);
                }
            }
        }
    }
}