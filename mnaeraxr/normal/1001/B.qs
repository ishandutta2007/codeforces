namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if (index == 0){
                H(qs[0]);
                CNOT(qs[0], qs[1]);
            }
            elif (index == 1){
                X(qs[0]);
                H(qs[0]);
                CNOT(qs[0], qs[1]);
            }
            elif (index == 2){
                H(qs[0]);
                X(qs[1]);
                CNOT(qs[0], qs[1]);
            }
            else{
                X(qs[0]);
                H(qs[0]);
                X(qs[1]);
                CNOT(qs[0], qs[1]);
            }
        }
    }

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);

            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Experiment(count : Int, index : Int) : (Int, Int, Int)
    {
        body
        {
            mutable numOnes = 0;
            mutable agree = 0;

            using (qubits = Qubit[2])
            {
                for (test in 1..count)
                {
                    Set (Zero, qubits[0]);
                    Set (Zero, qubits[1]);

                    Solve(qubits, index);

                    let v0 = M(qubits[0]);
                    let v1 = M(qubits[1]);

                    if (v0 == One)
                    {
                        set numOnes = numOnes + 1;
                    }

                    if (v0 == v1)
                    {
                        set agree = agree + 1;
                    }
                }

                Set(Zero, qubits[0]);
                Set(Zero, qubits[1]);
            }
            
            return (count-numOnes, numOnes, agree);
        }
    }
}