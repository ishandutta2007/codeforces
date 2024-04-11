namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            mutable n=Length(qs);
            H(qs[0]);
            for (index in 1..n-1) {
                CNOT(qs[0],qs[index]);
            }
        }
    }
}