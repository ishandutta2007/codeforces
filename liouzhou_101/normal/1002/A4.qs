namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            mutable n = Length(qs);
            mutable k = 0;
            //1 2 4 8 16
            if (n == 1)
            {
                set k = 0;
            }
            elif (n == 2)
            {
                set k = 1;
            }
            elif (n == 4)
            {
                set k = 2;
            }
            elif (n == 8)
            {
                set k = 3;
            }
            elif (n == 16)
            {
                set k = 4;
            }
            for (i in 0..k-1)
            {
                H(qs[i]);
            }
            mutable cur = n-1;
            for (i in 0..n-1)
            {
                if (i != 1 && i != 2 && i != 4 && i != 8 && i != 16)
                {
                    mutable bits = new Int[k];
                    mutable tmp = i;
                    for (j in 0..k-1)
                    {
                        set bits[j] = tmp%2;
                        set tmp = tmp/2;
                    }
                    for (j in 0..k-1)
                    {
                        if (bits[j] == 0)
                        {
                            X(qs[j]);
                        }
                    }
                    (Controlled X)(qs[0..k-1], qs[cur]);
                    for (j in 0..k-1)
                    {
                        if (bits[j] == 0)
                        {
                            X(qs[j]);
                        }
                    }
                    for (j in 0..k-1)
                    {
                        if (bits[j] == 1)
                        {
                            CNOT(qs[cur], qs[j]);
                        }
                    }
                    set cur = cur-1;
                }
            }
        }
    }

}