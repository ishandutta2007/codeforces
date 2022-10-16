namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation DumpUnitary (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = BoolArrFromPositiveInt(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");
                
                ResetAll(qs);
            }
        }
    }
    operation CSWAP(c: Qubit, x: Qubit, y: Qubit) : Unit {
        body(...) {
            CCNOT(c,x,y);
            CCNOT(c,y,x);
            CCNOT(c,x,y);
        }
        adjoint auto;
    }
    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 0..N-2) {
            CNOT(qs[N-1], qs[i]);
        }
        H(qs[N-1]);
        for (i in 0..N-2) {
            CNOT(qs[N-1], qs[i]);
        }
        Controlled H([qs[1], qs[2]], qs[0]);
        X(qs[1]); X(qs[2]);
        Controlled H([qs[1], qs[2]], qs[0]);
        X(qs[1]); X(qs[2]);

        X(qs[0]);
        CSWAP(qs[0], qs[1], qs[2]);
    }

    operation Tester(N : Int) : Unit {
        DumpUnitary(N, Solve);
    }
}