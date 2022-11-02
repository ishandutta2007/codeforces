namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation mod3add(control : Qubit, a : Qubit, b : Qubit) : Unit {
        body (...) {
            CCNOT(control, a, b);
            CCNOT(control, b, a);
            CNOT(control, b);
        }

        adjoint invert;
    }

    operation Solve(qs : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(qs);

            using (aux = Qubit[2]) {
                for (i in 0 .. Length(qs)-1) {
                    mod3add(qs[i], aux[0], aux[1]);
                }

                // now if LE == |00, xor y.
                MultiX(aux);
                CCNOT(aux[0], aux[1], y);
                MultiX(aux);

                for (i in 0 .. Length(qs)-1) {
                    (Adjoint mod3add)(qs[i], aux[0], aux[1]);
                }
            }
        }

        adjoint self;
    }
}