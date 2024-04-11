namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            unitary(q);
            X(q);
            unitary(q);
            let ans = M(q) == Zero ? 0 | 1;
            Reset(q);
            return ans;
        }
    }
}