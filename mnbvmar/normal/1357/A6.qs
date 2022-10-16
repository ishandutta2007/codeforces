namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            CNOT(qs[0], qs[1]);

            unitary(qs[1]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);

            let m0 = M(qs[0]) == One ? 1 | 0;
            let m1 = M(qs[1]) == One ? 1 | 0;
            ResetAll(qs);

            return m0 == 0 ? m1 | 3 - m1;
        }
    }
}