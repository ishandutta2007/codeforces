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

    // operation controlZ( x : Qubit, y : Qubit) : () {
    //     body {
    //         H(y);
    //         CNOT(x,y);
    //         H(y);
    //     }
    // }

    // operation perfE( x : Qubit, a : Double) : () {
    //     body {
    //         R(PauliX, -2.0*a, x);
    //     }
    // }

    // operation perfA( x : Qubit)  : (){
    //     body {
    //         (Adjoint S)(x);
    //         H(x);
    //         T(x);
    //         H(x);
    //         S(x);
    //         X(x);
    //         perfE(x, 1.1780972);
    //     }
    // }

    // operation perfB(x : Qubit)  : (){
    //     body {
    //         H(x);
    //         S(x);
    //         H(x);
    //         (Adjoint S)(x);
    //         H(x);
    //         (Adjoint T)(x);
    //         H(x);
    //         S(x);
    //         perfE(x, -0.39269908);
    //     }
    // }

    
    // operation perfC(x : Qubit)  : (){
    //     body {
    //         H(x);
    //         S(x);
    //         H(x);
    //         perfE(x, -0.7853981);
    //     }
    // }

    // operation magic(x: Qubit, y : Qubit) : () {
    //     body {
    //         perfC(x);
    //         controlZ(x, y);
    //         perfB(x);
    //         controlZ(x, y);
    //         perfA(x);
    //         perfE(y, 3.1415926);
    //     }
    // }

    operation ch(x:Qubit, y:Qubit) : () {
        body {
            // H(x);
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


    // operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    // {
    //     body
    //     {
    //         for (i in 0..Length(x)-1) {
    //             if (b[i] == 0) {
    //                 X(x[i]);
    //             }
    //             CNOT(x[i], y);
    //             if (b[i] == 0) {
    //                 X(x[i]);
    //             }
    //         }
    //     }
    // }

    // operation Power(p: Int) : (Int)
    // {
    //     body {
    //         mutable x = 1;
    //         for (i in 1..p) {
    //             set x = x * 2;
    //         }
    //         return x;
    //     }
    // }

    // operation Solve (qs : Qubit[]) : ()
    // {
    //     body
    //     {
    //         let n = Length(qs);
    //         let z = Power(n);
    //         mutable w = new Double[z];  
    //         mutable x = 1;
    //         for (i in 1..n) {
    //             set w[x] = 1.0;
    //             set x = x * 2;
    //         }   
            
    //         let op = StatePreparationPositiveCoefficients(w);
    //         let qbe = BigEndian(qs);
    //         op(qbe);
    //     }
    // }

    operation Solve (q : Qubit[]) : ()
    {
        body
        {
            if (Length(q) == 1) {
                X(q[0]);
            } else {
                H(q[0]);
                X(q[1]);
                CNOT(q[0],q[1]);
                if (Length(q) > 2) {
                    for (i in 0..1) {
                        ch(q[i],q[i+2]);
                        CNOT(q[i+2],q[i]);
                    }
                }
                if (Length(q) > 4) {
                    for (i in 0..3) {
                        ch(q[i],q[i+4]);
                        CNOT(q[i+4],q[i]);
                    }
                }
                if (Length(q) > 8) {
                    for (i in 0..7) {
                        ch(q[i],q[i+8]);
                        CNOT(q[i+8],q[i]);
                    }
                }
                
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
                    Solve(q);

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