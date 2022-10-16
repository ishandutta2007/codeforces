namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let N = Length(qs);
        let need_result = parity == 0 ? Zero | One;
        using (q_anc = Qubit()) {
            repeat {
                for (i in 0 .. N-1) {
                    H(qs[i]);
                    CNOT(qs[i], q_anc);
                }
            }
            until (M(q_anc) == need_result)
            fixup {
                ResetAll(qs);
                Reset(q_anc);
            }

            if (need_result == One) {
                X(q_anc);
            }
        }
    }
}