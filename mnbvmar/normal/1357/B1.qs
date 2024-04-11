namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Increment (register : LittleEndian) : Unit is Adj+Ctl {
        let N = Length(register!);
        if (N == 1) {
            X(register![0]);
        } else {
            Controlled Increment([register![0]], LittleEndian(register![1..N-1]));
            X(register![0]);
        }
    }
    
    operation Decrement (register : LittleEndian) : Unit is Adj+Ctl {
        Adjoint Increment(register);
    }
    
    operation CountDelta (inputs : Qubit[], number : LittleEndian) : Unit is Adj+Ctl {
        let N = Length(inputs);
        for (i in 0 .. N-1) {
            Controlled Increment([inputs[i]], number);
            X(inputs[i]);
            Controlled Decrement([inputs[i]], number);
            X(inputs[i]);
        }
    }
 
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (q_cnt = Qubit[4]) {
            let number = LittleEndian(q_cnt);
            CountDelta(inputs, number);
            (ControlledOnInt(0, X))(q_cnt, output);
            Adjoint CountDelta(inputs, number);
        }
    }

    operation IsBalanced(b : Bool[]) : Bool {
        let N = Length(b);
        using (qs = Qubit[N]) {
            for (i in 0 .. N - 1) {
                if (b[i]) {
                    X(qs[i]);
                }
            }

            using (output = Qubit()) {
                Solve(qs, output);
                let answer = M(output) == One;
                ResetAll(qs);
                Reset(output);
                return answer;
            }
        }
    }
}