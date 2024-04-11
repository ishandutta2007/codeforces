namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation XorGate(a : Qubit, b : Qubit, c : Qubit) : Unit {
        body (...) {
            CNOT(a, c);
            CNOT(b, c);
        }
        adjoint self;
    }

    operation OrGate(qs : Qubit[], ans : Qubit) : Unit {
        body (...) {
            MultiX(qs);
            (Controlled X)(qs, ans);
            // // not needed:
            // MultiX(qs); 
            X(ans);
        }
        adjoint invert;
    }

    operation F45(qs : Qubit[], aux : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);

            // aux[0] = |1iff not periodic iff
            // x_0 != x_{n-1}
            XorGate(qs[0], qs[n-1], aux[0]);
            
            // aux[3] = |1iff not periodic iff
            // x_0 != x_{n-2} || x_1 != x_{n-1}
            XorGate(qs[0], qs[n-2], aux[1]);
            XorGate(qs[1], qs[n-1], aux[2]);
            OrGate(aux[1 .. 2], aux[3]);
        }

        adjoint invert;
    }

    operation F67(qs : Qubit[], aux : Qubit[]) : Unit {
        body (...) {
            let n = Length(qs);

            F45(qs, aux);

            XorGate(qs[0], qs[n-3], aux[4]);
            XorGate(qs[1], qs[n-2], aux[5]);
            XorGate(qs[2], qs[n-1], aux[6]);
            OrGate(aux[4 .. 6], aux[7]);
        }

        adjoint invert;
    }

    operation Solve(qs : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(qs);
            
            if (n < 4) {
                // always check n = p-1
                using (aux1 = Qubit()) {
                    // aux[0] = |1iff not periodic iff
                    // x_0 != x_{n-1}
                    XorGate(qs[0], qs[n-1], aux1);

                    // if aux1 = |1, x0 != x_{n-1} so it is not periodic
                    CNOT(aux1, y);
                    X(y);

                    // undo operation:
                    XorGate(qs[0], qs[n-1], aux1);
                }
            } elif (n < 6) {
                using (aux = Qubit[4]) {
                    F45(qs, aux);

                    CCNOT(aux[0], aux[3], y);
                    X(y);

                    // undo operations
                    (Adjoint F45)(qs, aux);
                }
            } else {
                using (aux = Qubit[8]) {
                    F67(qs, aux);

                    (Controlled X)([ aux[0], aux[3], aux[7] ], y);
                    X(y);

                    (Adjoint F67)(qs, aux);
                }
            }
        }

        adjoint invert;
    }

    operation HelloQ () : Unit {
        let n = 6;
         using ((r, Q) = (Qubit(), Qubit[n])) {
             for (j in 0.. (1<<<n)-1) {
                 for (i in 0..n-1) {
                     if (((j >>> i) &&& 1) != 0) {
                         X(Q[i]);
                     }
                 }
 
                 Solve(Q, r);
                 let ans = M(r);
                 Message($"F({j}) = {ans}");
                 ResetAll(Q + [r]);
             }
         }
    }
}