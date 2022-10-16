namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            unitary(qs);
            if (M(qs[1]) == Zero) {
                return 1;
            } else {
                X(qs[1]);
                return 0;
            }
        }
    }
}