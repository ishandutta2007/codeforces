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

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let n = Length(qs);
            for(i in 0..n-1){
                if(bits0[i] != bits1[i]){
                    if(M(qs[i]) == Zero){
                        if(!bits0[i]){
                            return 0;
                        }
                        return 1;
                    }
                    else {
                        if(bits0[i]){
                            return 0;
                        }
                        return 1;
                    }
                }
            }
            return -1;
        }
    }
}