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
            H(qs[0]);
            H(qs[1]);
            if (M(qs[0]) == One) {
                if (M(qs[1]) == One) {
                    return 3;
                } else {
                    return 2;
                }
            } else {
                if (M(qs[1]) == One) {
                    return 1;
                } else {
                    return 0;
                }
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

    operation BellTest (count : Int, type: Int) : (Int,Int,Int,Int)
    {
        body
        {
            
            mutable num00 = 0;
            mutable num01 = 0;
            mutable num10 = 0;
            mutable num11 = 0;
            using (q = Qubit[2])
            {
                for (test in 1..count) {
                    Set(Zero, q[0]);
                    Set(Zero, q[1]);
                    if (type %2 == 1) {
                        X(q[1]);
                    }
                    if (type >= 2) {
                        X(q[0]);
                    }
                    H(q[0]);
                    H(q[1]);
                    
                    H(q[0]);
                    H(q[1]);
                    // CNOT(q[0], q[1]);
                    let res = M(q[0]);
                    let res2 = M(q[1]);
                    if (res == One) {
                        if (res2 == One) {
                            set num11 = num11 + 1;
                        } else { 
                            set num10 = num10 + 1;
                        }
                    } else {
                        if (res2 == One) {
                            set num01 = num01 + 1;
                        } else { 
                            set num00 = num00 + 1;
                        }
                    }

                    Set(Zero, q[0]);
                    Set(Zero, q[1]);
                }
            }
            return (num00, num01, num10, num11);
        }
    }
}