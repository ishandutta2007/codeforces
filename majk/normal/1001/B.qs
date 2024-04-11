namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;


    // operation Solve(q : Qubit, sign : Int) : ()
    // {
    //     body
    //     {
    //         if (sign == -1) X(q);
    //         H(q);
    //     }
    // }

    operation Solve(q: Qubit[], index: Int) : () {
        body {
            if (index == 1 || index == 3) { X(q[0]); }
            if (index >= 2) { X(q[1]); } 
            //if (index >= 2) { X(q[0]); }
            // if (index == 1 || index == 3) { X(q[1]); }
            H(q[0]);
            CNOT(q[0],q[1]);
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

    operation BellTest (count : Int, first: Result, second: Result) : (Int,Int,Int)
    {
        body
        {
            mutable numOnes = 0;
            mutable agree = 0;
            using (qubits = Qubit[2])
            {
                for (test in 1..count)
                {
                    Set (first, qubits[0]);
                    Set (second, qubits[1]);

                    H(qubits[0]);
                    CNOT(qubits[0],qubits[1]);
                    let res = M (qubits[0]);

                    if (M (qubits[1]) == res) {
                        set agree = agree + 1;
                    }

                    // Count the number of ones we saw:
                    if (res == One)
                    {
                        set numOnes = numOnes + 1;
                    }
                }

                Set(Zero, qubits[0]);
                Set(Zero, qubits[1]);
            }
            // Return number of times we saw a |0> and number of times we saw a |1>
            return (count-numOnes, numOnes, agree);
        }
    }
}