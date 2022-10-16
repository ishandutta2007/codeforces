namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        using (q_anc = Qubit()) {
            repeat {
                for (i in 0 .. N-1) {
                    H(qs[i]);
                }
                (ControlledOnInt(2^N - 1, X))(qs, q_anc);
            }
            until (M(q_anc) == Zero)
            fixup {
                for (i in 0 .. N-1) {
                    X(qs[i]);
                }
                X(q_anc);
            }
        }
    }
}