namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable ret = -1;
            using (p = Qubit[1])
            {
                H(p[0]);
                (Controlled H)(p, q);
                if (M(p[0]) == Zero)
                {
                    if (M(q) == Zero)
                    {
                        set ret = -1;
                    }
                    else
                    {
                        set ret = 1;
                    }
                }
                else
                {
                    if (M(q) == Zero)
                    {
                        set ret = -1;
                    }
                    else
                    {
                        set ret = 0;
                    }
                }
                ResetAll(p);
            }
            return ret;
        }
    }

}