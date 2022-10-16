namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            X(qs[0]);
            unitary(qs);
            let a = M(qs[0]);
            let b = M(qs[1]);
            ResetAll(qs);
            mutable ans = 0;
            
            if (a == One and b == One) {
                set ans = 1;
            } elif (a == Zero and b == One) {
                set ans = 3;
            } else {
                X(qs[1]);
                unitary(qs);
                set ans = M(qs[0]) == One ? 2 | 0;
                ResetAll(qs);
            }

            return ans;
        }
    }
}