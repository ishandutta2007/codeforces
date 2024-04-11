namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        mutable res = true;
        using (qs = Qubit[N]) {
            using (y = Qubit[1]) {
                X(y[0]);
                for (i in 0 .. N - 1) {
                    H(qs[i]);
                }
                H(y[0]);
                Uf(qs, y[0]);
                for (i in 0 .. N - 1) {
                    H(qs[i]);
                }
                for (i in 0 .. N - 1) {
                    if (M(qs[i]) != Zero) {
                        set res = false;
                    }
                }

                ResetAll(y);
            }
            ResetAll(qs);
        }
        return res;
    }
}