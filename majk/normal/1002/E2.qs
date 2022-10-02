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

    // controlled hadamard
    operation ch(x:Qubit, y:Qubit) : () {
        body {
            S(x);
            H(y);
            (Adjoint S)(y);
            CNOT(x,y);
            H(y);
            T(y);
            CNOT(x,y);
            T(y);
            H(y);
            S(y);
            X(y);
        }
    }


    // operation Solve (q : Qubit[]) : ()
    // {
    //     body
    //     {
    //         if (Length(q) == 1) {
    //             X(q[0]);
    //         } else {
    //             H(q[0]);
    //             X(q[1]);
    //             CNOT(q[0],q[1]);
    //             if (Length(q) > 2) {
    //                 for (i in 0..1) {
    //                     ch(q[i],q[i+2]);
    //                     CNOT(q[i+2],q[i]);
    //                 }
    //             }
    //             if (Length(q) > 4) {
    //                 for (i in 0..3) {
    //                     ch(q[i],q[i+4]);
    //                     CNOT(q[i+4],q[i]);
    //                 }
    //             }
    //             if (Length(q) > 8) {
    //                 for (i in 0..7) {
    //                     ch(q[i],q[i+8]);
    //                     CNOT(q[i+8],q[i]);
    //                 }
    //             }
                
    //         }
    //     }
    // }

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

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable ans = new Int[N];

            using (x = Qubit[N]) {
                for (i in 0..N-1) {
                    Set(Zero, x[i]);
//                    H(x[i]);
                }

                using (y = Qubit[1]) {
                    // Set(One, y[0]);
                    // H(y[0]);
                    // Uf(x, y[0]);
                    // for (i in 0..N-1) {
                    //     H(x[i]);
                    // }
                    Set(Zero, y[0]);
                    Uf(x, y[0]);
                    if (M(y[0]) == Zero) {
                        if (N%2 == 1) {
                        set ans[0] = 1;
                        }
                    } elif (N%2 == 0) {
                        set ans[0] = 1;
                    }

                     Set(Zero, y[0]);
                   
                    // for (i in 0..N-1) {
                    //     let res = MResetZ(x[i]);
                    //     if (res == One) {
                    //         set ans[i] = 1;
                    //     }
                    // }
                    // Reset(y[0]);
                }

                for (i in 0..N-1) {
                    Set(Zero, x[i]);
                }
            }
           
            return ans;
        }
    }

    operation BellTest (count : Int) : (Int[])
    {
        body
        {
            let size = 1;
            mutable res = new Int[size+1];
            using (q = Qubit[size])
            {
                for (test in 1..count)
                {
                    // H(q[0]);
                    // X(q[1]);
                    // CNOT(q[0],q[1]);

                    // ch(q[0],q[2]);
                    // CNOT(q[2],q[0]);

                    // ch(q[1],q[3]);
                    // CNOT(q[3],q[1]);

                    // ch(q[0],q[4]);
                    // CNOT(q[4],q[0]);


                    // ch(q[1],q[5]);
                    // CNOT(q[5],q[1]);
                    // Solve(q);

                    mutable cnt = 0;
                    for (i in 0..size-1) {
                        if (M(q[i]) == One) {
                            set cnt = cnt + 1;
                            set res[i] = res[i] + 1;
                        }
                    }
                    if (cnt > 1) {
                        set res[size] = res[size] + 1;
                    }

                    for (i in 0..size-1) {
                        Set(Zero, q[i]);
                    }
                }
            }
            return (res);
        }
    }


    // operation BellTest (count : Int) : (Int[])
    // {
        // body
        // {
            
        //     let size = 2;
//             mutable arr = new Int[size + 1];
//             using (q = Qubit[size])
//             {
//                 for (test in 1..count) {
//                     H(q[0]);
//                     X(q[2]);
//                     CNOT(q[0],q[2]);
//                     // mutable WWW = [q[0], q[1]];
//                     let qbe = BigEndian(q[0..1]);
//                     (Adjoint op2)(qbe);
//                     // op1(qbe);
//                     // X(q[0]);
//                     // X(q[1]);

// //                    Solve(q);

//                     mutable cnt = 0;
//                     for (i in 0..size-1) {
//                         if (M(q[i]) == One) {
//                             set cnt = cnt + 1;
//                             set arr[i] = arr[i] + 1;
//                         }
//                     }

//                     if (cnt > 1) {
//                         set arr[size] = arr[size] + 1;
//                     }

//                     for (i in 0..size-1) {
//                         Set(Zero, q[i]);
//                     }
//                 }
//             }
            // return (arr);
        // }
    // }
}