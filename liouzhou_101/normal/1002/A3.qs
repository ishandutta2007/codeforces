namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable n = Length(qs);
            mutable a = new Bool[n];
            mutable b = new Bool[n];
            mutable pos = 0;
            for (i in 0..n-1)
            {
                set a[i] = bits0[i];
                set b[i] = bits1[i];
                if (a[i] != b[i])
                {
                    set pos = i;
                }
            }
            if (a[pos] != false)
            {
                for (i in 0..n-1)
                {
                    mutable tmp = a[i];
                    set a[i] = b[i];
                    set b[i] = tmp;
                }
            }
            H(qs[pos]);
            for (i in 0..n-1)
            {
                if (i != pos)
                {
                    if (a[i] == b[i] && a[i] == true)
                    {
                        X(qs[i]);
                    }
                    elif (a[i] != b[i] && b[i] == true)
                    {
                        CNOT(qs[pos], qs[i]);
                    }
                    elif (a[i] != b[i] && b[i] == false)
                    {
                        X(qs[pos]);
                        CNOT(qs[pos], qs[i]);
                        X(qs[pos]);
                    }
                    else
                    {
                    }
                }
            }
        }
    }

}