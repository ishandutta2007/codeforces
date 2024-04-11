namespace Solution {
    //open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit) : Int
    {
        if (Microsoft.Quantum.Intrinsic.Random([0.5, 0.5]) == 0) {
            if (M(q) == One) {
                return 1;
            } else {
                return -1;
            }
        } else {
            H(q);
            if (M(q) == One) {
                return 0;
            } else {
                return -1;
            }
        }
    }
}