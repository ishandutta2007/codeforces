namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (qs : Qubit[]) : Unit {
        using (q_anc = Qubit()) {
            repeat {
                H(qs[0]);
                H(qs[1]);
                (ControlledOnInt(0, X))([qs[0], qs[1]], q_anc);
            }
            until (M(q_anc) == Zero)
            fixup {
                X(q_anc);
            }
        }
    }
}