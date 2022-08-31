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

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            if (M(q) == Zero)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}