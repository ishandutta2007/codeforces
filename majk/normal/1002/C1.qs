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


    operation Solve (q : Qubit) : Int
    {
        body
        {
            Ry(0.785, q);
            if (M(q) == One) {
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

    operation BellTest (count : Int) : (Int)
    {
        body
        {
            mutable ok = 0;
            using (q = Qubit[2])
            {
                for (test in 1..count) {
                    H(q[1]);
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
            
                    Ry(0.785, q[0]);
                    Ry(0.785, q[1]);
                    
                    if (M(q[0]) == Zero) {
                        set ok = ok + 1;
                    }
                    if (M(q[1]) == One) {
                        set ok = ok + 1;
                    }

                    Set(Zero, q[0]);
                    Set(Zero, q[1]);
                }
            }
            return ok;
        }
    }
}