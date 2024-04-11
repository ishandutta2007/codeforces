namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;


    // X(q); // 0 -> 1
    // H(q); // 0 -> +; 1 -> -
    // 
    // Bell |00> + |11>
    // H(q[0]); CNOT(q[0],q[1]);
    // to put "-": X(q[0]);
    // to switch to |01> +- |10>: X(q[1]);
    // 
    // GHZ: 
    // H(q[0])
    // for (i in 1..Length(q)) CNOT(q[0],q[i])
    // 
    // output oracle x[k] => y:
    //        CNOT(x[k],y) 


    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable ans = 0;
            for (i in 0..Length(qs)-1) {
                if (M(qs[i]) == One) {
                    set ans = ans + 1;
                }
            }
            if (ans == 1) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    operation Bell(q: Qubit[], index: Int) : () {
        body {
            if (index == 1 || index == 3) { X(q[0]); }
            if (index >= 2) { X(q[1]); } 
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

    operation BellTest (count : Int) : (Int[])
    {
        body
        {
            mutable i = new Int[16];
            using (qubits = Qubit[4])
            {
                mutable b = new Bool[4];
                mutable c = new Bool[4];
                set b[0] = true;
                set c[0] = true;
                set b[2] = true;
                set c[3] = true;
                // 1010
                // // 1001
                // for (test in 1..count)
                // {
                //     Set(Zero, qubits[0]);
                //     Set(Zero, qubits[1]);
                //     Set(Zero, qubits[2]);
                //     Set(Zero, qubits[3]);
                //     Solve(qubits, b, c);
                //     mutable x = 0;
                //     if (M(qubits[0]) == One) { set x = x + 8; }
                //     if (M(qubits[1]) == One) { set x = x + 4; }
                //     if (M(qubits[2]) == One) { set x = x + 2; }
                //     if (M(qubits[3]) == One) { set x = x + 1; }
                //     set i[x] = i[x] + 1;
                // }
            
                Set(Zero, qubits[0]);
                Set(Zero, qubits[1]);
                Set(Zero, qubits[2]);
                Set(Zero, qubits[3]);
            }
            return (i);
        }
    }
}