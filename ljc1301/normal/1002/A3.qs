namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
mutable t=-1;
            for(i in 0..Length(qs)-1)
            {
                if(bits0[i]!=bits1[i])
                {
                    set t=i;
                }
            }
            if(t==-1)
            {
                for(i in 0..Length(qs)-1)
                {
                    if(bits0[i])
                    {
                        X(qs[i]);
                    }
                }
            }
            else
            {
                H(qs[t]);
                for(i in 0..Length(qs)-1)
                {
                    if(bits0[i]==bits1[i])
                    {
                        if(bits0[i])
                        {
                            X(qs[i]);
                        }
                    }
                    else
                    {
                        if(i!=t)
                        {
                            if(bits0[i]!=bits0[t])
                            {
                                X(qs[i]);
                            }
                            CNOT(qs[t],qs[i]);
                        }
                    }
                }
            }
        }
    }
}