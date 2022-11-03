namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable res=0;
            let len=Length(qs);
            for(i in 0..len-1)
            {
                if(M(qs[i])==One)
                {
                    set res=res+1;
                }
            }
            if(res==len)
            {
                set res=0;
            }
            return res;
        }
    }
}