namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let m0 = M(qs[0]);
            let m1 = M(qs[1]);
            if (m0 == Zero && m1 == Zero)
            {
                return 0;
            }
            elif (m0 == One && m1 == Zero)
            {
                return 1;
            }
            elif (m0 == Zero && m1 == One)
            {
                return 2;
            }
            else
            {
                return 3;
            }
        }
    }
}