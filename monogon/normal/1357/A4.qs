namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        mutable ans = 1;
        using(q1 = Qubit()) {
            using(q2 = Qubit()) {
                H(q1);
                Controlled unitary([q1], (2.0 * 3.1415926535897931, q2));
                H(q1);
                if(M(q1) == One) {
                    set ans = 0;
                }
                Reset(q2);
            }
            Reset(q1);
        }
        return ans;
    }
}