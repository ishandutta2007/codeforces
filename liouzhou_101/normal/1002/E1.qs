namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable ret = new Int[N];
            using (x = Qubit[N+1])
            {
                X(x[N]);
                for (i in 0..N)
                {
                    H(x[i]);
                }
                Uf(x[0..N-1], x[N]);
                for (i in 0..N-1)
                {
                    H(x[i]);
                }
                for (i in 0..N-1)
                {
                    if (M(x[i]) == Zero)
                    {
                        set ret[i] = 0;
                    }
                    else
                    {
                        set ret[i] = 1;
                    }
                }
                ResetAll(x);
            }
            return ret;
        }
    }

}