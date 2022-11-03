namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable res=-1;
            using(qs = Qubit[1])
            {
                H(qs[0]);
                if(M(qs[0])==Zero)
                {
                    if(M(q)==One)
                    {
                        set res=1;
                    }
                }
                else
                {
                    H(q);
                    if(M(q)==One)
                    {
                        set res=0;
                    }
                }
                ResetAll(qs);
            }
            return res;
        }
    }
}