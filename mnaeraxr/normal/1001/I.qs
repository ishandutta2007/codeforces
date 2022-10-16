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

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable ok = true;

            using (q = Qubit[N + 1])
            {
                for (i in 0..N-1)
                {
                    Set(Zero, q[i]);
                    H(q[i]);
                }
                Set(One, q[N]);
                H(q[N]);

                Uf(q[0..N-1], q[N]);

                for (i in 0..N-1)
                {
                    H(q[i]);
                }

                for (i in 0..N-1)
                {
                    let obs = M(q[i]);

                    if (obs == One)
                    {
                        set ok = false;
                    }
                }

                ResetAll(q);
            }

            return ok;
        }
    }
}