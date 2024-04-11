namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        mutable equal = true;
        mutable ind = 0;
        for (i in 0 .. Length(qs) - 1) {
            if (bits0[i] == bits1[i]) {
                if (bits0[i]) {
                    X(qs[i]);
                }
            } else {
                if (equal) {
                    H(qs[i]);
                    set equal = false;
                    set ind = i;
                } else {
                    if (!bits0[ind]) {
                        if (bits0[i]) {
                            X(qs[ind]);
                            CNOT(qs[ind], qs[i]);
                            X(qs[ind]);
                        } else {
                            CNOT(qs[ind], qs[i]);
                        }
                    } else {
                        if (!bits0[i]) {
                            X(qs[ind]);
                            CNOT(qs[ind], qs[i]);
                            X(qs[ind]);
                        } else {
                            CNOT(qs[ind], qs[i]);
                        }
                    }
                }
            }
        }
    }
}