namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve(qs : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(qs);
            if (n == 1) {
                X(y);
            } else {
                if (n > 2) {
                    for (i in 2 .. n-1) {
                        if ((i &&& 1) == 0) {
                            X(qs[i]);
                        }
                    }
                }
                for (i in 1 .. n-1) {
                    CNOT(qs[0], qs[i]);
                }

                (Controlled X)(qs[1 .. n-1], y);
                
                for (i in 1 .. n-1) {
                    CNOT(qs[0], qs[i]);
                }
                if (n > 2) {
                    for (i in 2 .. n-1) {
                        if ((i &&& 1) == 0) {
                            X(qs[i]);
                        }
                    }
                }
            }
        }

        adjoint invert;
    }
}