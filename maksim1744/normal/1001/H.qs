namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        for (k in 0 .. Length(x) - 1) {
            CNOT(x[k], y);
        }
    }
}