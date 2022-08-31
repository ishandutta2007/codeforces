namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[]) : ()
    {
        body (...) {
            if (Length(qs) == 1) {
                X(qs[0]);
            } else {
                Ry(ArcSin(1.0 / Sqrt(IntAsDouble(Length(qs)))) * 2.0, qs[0]);
                X(qs[0]);
                (Controlled Solve)([qs[0]], qs[1..Length(qs)-1]);
                X(qs[0]);
            }
        }

        controlled auto;
    }
}