namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            unitary(q);
            if (M(q) == Zero) {
                return 0;
            } else {
                X(q);
                return 1;
            }
        }
    }
}