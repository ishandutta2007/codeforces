namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable res=true;
            using (qs = Qubit[N+1])
            {
                for(i in 0..N-1)
                {
                    H(qs[i]);
                }
                X(qs[N]);
                H(qs[N]);
                Uf(qs[0..N-1],qs[N]);
                for(i in 0..N-1)
                {
                    H(qs[i]);
                    if(M(qs[i])==One)
                    {
                        set res=false;
                    }
                }
                ResetAll(qs);
            }
            return res;
        }
    }
}