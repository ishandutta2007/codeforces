namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;

    operation SolveInc (register : LittleEndian) : Unit is Adj+Ctl {
        let N = Length(register!);
        if (N == 1) {
            X(register![0]);
        } else {
            Controlled SolveInc([register![0]], LittleEndian(register![1..N-1]));
            X(register![0]);
        }
    }

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        Adjoint SolveInc(register);
    }
}