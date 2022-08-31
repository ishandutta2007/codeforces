namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        for (i in 0 .. Length(qs) - 1) {
            if (bits0[i]) {
                X(qs[i]);
            }
        }
        mutable res = 0;
        for (i in 0 .. Length(qs) - 1) {
            if (M(qs[i]) != Zero) {
                set res = 1;
            }
        }
        return res;
    }
}