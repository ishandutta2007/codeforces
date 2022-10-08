namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        mutable flag = false;
        repeat {
            H(qs[0]);
            H(qs[1]);
            using(q = Qubit()) {
                CCNOT(qs[0], qs[1], q);
                if(M(q) == Zero) {
                    set flag = true;
                }
                Reset(q);
            }
            if(not flag) {
                Reset(qs[0]);
                Reset(qs[1]);
            }
        }until(flag);
        X(qs[0]);
        X(qs[1]);
    }
}