namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable res=0;
            for(i in 0..Length(qs)-1)
            {
                let m=M(qs[i]);
                if((m==One && !bits0[i]) || (m==Zero && bits0[i]))
                {
                    set res=1;
                }
            }
            return res;
        }
    }
}