namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation CSWAP(c: Qubit, x: Qubit, y: Qubit) : Unit {
        body(...) {
            CCNOT(c,x,y);
            CCNOT(c,y,x);
            CCNOT(c,x,y);
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            using(ts = Qubit[4]) {
                X(ts[0]);
                for (p in 0 .. N - 1) {
                    CSWAP(x[p], ts[2], ts[3]);
                    CSWAP(x[p], ts[1], ts[2]);
                    CSWAP(x[p], ts[0], ts[1]);
                    CSWAP(x[p], ts[3], ts[0]);
                }
                CNOT(ts[0], y);

                for (p in 0 .. N - 1) {
                    CSWAP(x[p], ts[2], ts[3]);
                    CSWAP(x[p], ts[1], ts[2]);
                    CSWAP(x[p], ts[0], ts[1]);
                    CSWAP(x[p], ts[3], ts[0]);
                }
                for (p in 0 .. N - 1) {
                    CSWAP(x[p], ts[2], ts[3]);
                    CSWAP(x[p], ts[1], ts[2]);
                    CSWAP(x[p], ts[0], ts[1]);
                    CSWAP(x[p], ts[3], ts[0]);
                }
                X(ts[0]);
            }
        }
        adjoint auto;
    }
}