namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            Controlled unitary([qs[0]], (2.0 * PI(), qs[1]));
            H(qs[0]);
            let ans = M(qs[0]) == Zero ? 1 | 0;
            ResetAll(qs);
            return ans;
        }
    }
}