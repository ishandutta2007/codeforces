namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        let n = Length(qs);
        mutable flag = false;
        repeat {
            using(q = Qubit()) {
                for(i in 0..n-1) {
                    Reset(qs[i]);
                    H(qs[i]);
                }
                Controlled X(qs[0..n-1], q);
                if(M(q) == Zero) {
                    set flag = true;
                }
                Reset(q);
            }
        }until(flag);
    }
}