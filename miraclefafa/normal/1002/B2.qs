namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let n=Length(qs);
            for (i in 1..n-1) {
                CNOT(qs[0],qs[i]);
            }
            H(qs[0]);
            for (i in 0..n-1) {
                if (M(qs[i])==One) {
                    return 1;
                }
            }
            return 0;
        }
    }
}