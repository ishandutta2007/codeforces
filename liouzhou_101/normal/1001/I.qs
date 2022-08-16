namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable ret = true;
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
                    if (M(x[i]) != Zero)
                    {
                        set ret = false;
                    }
                }
                ResetAll(x);
            }
            return ret;
        }
    }
}