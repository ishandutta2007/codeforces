namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
 
    operation Increment (q3 : Qubit[]) : Unit is Adj+Ctl {
        SWAP(q3[0], q3[1]);
        SWAP(q3[0], q3[2]);
    }
    
    operation Decrement (q3 : Qubit[]) : Unit is Adj+Ctl {
        Adjoint Increment(q3);
    }
    
    operation CountMod (inputs : Qubit[], q3 : Qubit[]) : Unit is Adj+Ctl {
        let N = Length(inputs);
        for (i in 0 .. N-1) {
            if (i % 2 == 0) {
                Controlled Increment([inputs[i]], q3);
            } else {
                Controlled Decrement([inputs[i]], q3);
            }
        }
    }
 
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (q3 = Qubit[3]) {
            X(q3[0]);
            CountMod(inputs, q3);
            CNOT(q3[0], output);
            Adjoint CountMod(inputs, q3);
            X(q3[0]);
        }
    }
}