namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 1;
        using(q = Qubit()) {
            X(q);
            unitary(q);
            H(q);
            unitary(q);
            H(q);
            if(M(q) == One) {
                set ans = 0;
            }
            Reset(q);
        }
        return ans;
    }
}