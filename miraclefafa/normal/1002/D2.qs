namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            let n=Length(b);
            for (i in 0..n-1) {
                if (b[i]==1) {
                    CNOT(x[i],y);
                }
            }
            for (i in 0..n-1) {
                X(x[i]);
            }
            for (i in 0..n-1) {
                if (b[i]==0) {
                    CNOT(x[i],y);
                }
            }
            for (i in 0..n-1) {
                X(x[i]);
            }
            // your code here
        }
    }
}