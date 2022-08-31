namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Set (q1: Qubit, desired: Result) : ()
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

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            Set(qs[0], Zero);
            Set(qs[1], Zero);
            if (index == 1)
            {
                X(qs[0]);
            }
            elif (index == 2)
            {
                X(qs[1]);
            }
            elif (index == 3)
            {
                X(qs[0]);
                X(qs[1]);
            }
            H(qs[0]);
            CNOT(qs[0], qs[1]);
        }
    }
}