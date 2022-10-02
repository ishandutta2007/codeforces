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

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            for (i in 0..Length(x)-1) {
                if (b[i] == 0) {
                    X(x[i]);
                }
                CNOT(x[i], y);
                if (b[i] == 0) {
                    X(x[i]);
                }
            }
        }
    }

    operation Power(p: Int) : (Int)
    {
        body {
            mutable x = 1;
            for (i in 1..p) {
                set x = x * 2;
            }
            return x;
        }
    }

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
            mutable amp1 = [0.0; 1.0; 1.0; 1.4142135623];
            mutable amp2 = [1.0; 0.0; 1.0; 0.0];
            let op1 = StatePreparationPositiveCoefficients(amp1);
            let op2 = StatePreparationPositiveCoefficients(amp2);

            let size = 4;
            mutable arr = new Int[size + 1];
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
            return (arr);
        }
    }
}