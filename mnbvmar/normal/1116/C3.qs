namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Rotate (x : Qubit[]) : Unit is Adj+Ctl {
        SWAP(x[0], x[1]);
        SWAP(x[0], x[2]);
    } 

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            using (anc = Qubit[3]) {
                X(anc[0]);
                for (j in 0..N-1) {
                    Controlled Rotate([x[j]], anc);
                }
                CNOT(anc[0], y);
                for (j in 0..N-1) {
                    Controlled Adjoint Rotate([x[j]], anc);
                }
                X(anc[0]);
            } 
        }
        adjoint auto;
    }
}