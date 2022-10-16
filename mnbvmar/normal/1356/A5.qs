namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            
            Controlled unitary([qs[0]], qs[1]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            
            let result = M(qs[0]) == One ? 0 | 1;
            ResetAll(qs);
            return result;
        }
    }
}