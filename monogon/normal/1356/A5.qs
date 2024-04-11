namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using(q1 = Qubit()) {
            using(q2 = Qubit()) {
                H(q1);
                Controlled unitary([q1], q2);
                H(q1);
                if(M(q1) == One) {
                    set res = 1;
                }
                Reset(q2);
            }
            Reset(q1);
        }
        return res;
    }
}