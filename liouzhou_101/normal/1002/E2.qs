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
                Uf(x[0..N-1], x[N]);
                if (M(x[N]) == Zero)
                {
                    for (i in 0..N-1)
                    {
                        set ret[i] = 1;
                    }
                }
                else
                {
                    for (i in 0..N-1)
                    {
                        set ret[i] = 1;
                    }
                    set ret[0] = 0;
                }
                ResetAll(x);
            }
            return ret;
        }
    }

}