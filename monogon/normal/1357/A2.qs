namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using(q1 = Qubit()) {
            using(q2 = Qubit()) {
                X(q1);
                X(q2);
                // (1, 1)
                unitary([q1, q2]);
                let r1 = M(q1);
                let r2 = M(q2);
                if(r1 == Zero and r2 == One) {
                    set ans = 2;
                }elif(r1 == One and r2 == Zero) {
                    set ans = 1;
                }else {
                    X(q1);
                    unitary([q1, q2]);
                    if(M(q1) == One) {
                        set ans = 3;
                    }else {
                        set ans = 0;
                    }
                }
                Reset(q2);
            }
            Reset(q1);
        }
        return ans;
    }
}