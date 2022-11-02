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
            let n = Length(qs);

            for (i in 1 .. n-1) {
                CNOT(qs[0], qs[i]);
            }

            H(qs[0]);
            for (i in 1 .. n-1) {
                CNOT(qs[0], qs[i]);
            }
        }
        adjoint invert;
    }

    operation HelloQ () : Unit {
        DumpUnitaryToFiles(3, Solve);
    }
}