namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation SolveXZ (qs : Qubit[], unitary : (Qubit => Unit is Adj+Ctl)) : Bool {
        H(qs[0]);
        Controlled unitary([qs[0]], qs[1]);
        CNOT(qs[0], qs[1]);
        H(qs[0]);
        let is_pos = M(qs[0]) == Zero;
        ResetAll(qs);
        return is_pos;
    }

    operation SolveY (qs : Qubit[], unitary : (Qubit => Unit is Adj+Ctl)) : Bool {
        H(qs[0]);
        Controlled unitary([qs[0]], qs[1]);
        CNOT(qs[0], qs[1]);
        S(qs[0]);
        H(qs[0]);
        let is_pos = M(qs[0]) == One;
        ResetAll(qs);
        return is_pos;
    }

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            Controlled unitary([qs[0]], qs[1]);
            Controlled unitary([qs[0]], qs[1]);
            H(qs[0]);

            let is_xz = M(qs[0]) == One;
            ResetAll(qs);

            if (is_xz) {
                return SolveXZ(qs, unitary) ? 3 | 1;
            } else {
                return SolveY(qs, unitary) ? 0 | 2;
            }
        }
    }
}