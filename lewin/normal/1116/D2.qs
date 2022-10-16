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

    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 0 .. N - 2) {
            if (i > 0) {ApplyToEach(X, qs[N-i..N-1]);}
            ApplyToEach(Controlled H(qs[N-i-1..N-1], _), qs[0..N-i-2]);
            if (i > 0) {ApplyToEach(X, qs[N-i..N-1]);}
        }
    }

    operation Tester(N : Int) : Unit {
        DumpUnitary(N, Solve);
    }
}