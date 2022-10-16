namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(qs : Qubit[]) : Int
    {
        body{
            CNOT(qs[0], qs[1]);
            H(qs[0]);

            let b = M(qs[0]);
            let c = M(qs[1]);

            if (c == Zero)
            {
                if (b == Zero)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                if (b == Zero)
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
}