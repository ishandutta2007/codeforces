namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using(q = Qubit()) {
            H(q);
            unitary(q);
            H(q);
            let r = M(q);
            if(r == One) {
                X(q);
                set res = 1;
            }
        }
        return res;
    }
}