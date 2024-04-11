namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res = 1;
        using(q1 = Qubit()) {
            using(q2 = Qubit()) {
                let arr = [q1, q2];
                unitary(arr);
                if(M(q2) == One) {
                    set res = 0;
                    X(q2);
                }
            }
        }
        return res;
    }
}