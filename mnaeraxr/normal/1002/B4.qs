namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);

            let x0 = M(qs[0]);
            let x1 = M(qs[1]);

            if (x0 == Zero)
            {
                if (x1 == Zero){
                    return 3;
                }
                else{
                    return 2;
                }
            }
            else{
                if (x1 == Zero){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
}