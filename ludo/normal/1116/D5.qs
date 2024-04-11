namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    open Microsoft.Quantum.Extensions.Diagnostics;
    
    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
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
    
    operation Solve(qs : Qubit[]) : Unit {
        body (...) {
            // assert(n == 3);

            let a = qs[2];
            let b = qs[1];
            let c = qs[0];

            using (d = Qubit()) {
                CNOT(a, d);
                CNOT(b, d);

                // if d = |1, send:
                // abc
                // 010 -> |10+
                // 011 -> |01-
                // 100 -> |01+
                // 101 -> |10-
                CCNOT(d, c, a);
                CCNOT(d, c, b);
                CNOT(d, a);
                CNOT(d, b);
                (Controlled H)([d], c);

                X(d);
                // now d = |0, send 000 -> |EPR|+.
                CCNOT(d, a, b);
                (Controlled H)([d], a);
                (Controlled H)([d], c);
                CCNOT(d, a, b);

                X(d);

                CNOT(a, d);
                CNOT(b, d);
            }
        }
        adjoint invert;
    }

    operation HelloQ () : Unit {
        DumpUnitaryToFiles(3, Solve);
    }
}