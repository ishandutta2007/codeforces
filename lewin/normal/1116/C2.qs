namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation EvaluateEqualityClauses (x : Qubit[], p : Int, o : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            for (i in 0 .. N - p - 1) {
                CNOT(x[i+p], x[i]);
                X(x[i]);
            }

            Controlled X(x[0 .. N - p - 1], o);

            for (i in N - p - 1 .. -1 .. 0) {
                X(x[i]);
                CNOT(x[i+p], x[i]);
            }
        }
        adjoint auto;
    }


    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let N = Length(x);
            using (res=Qubit[N - 1]) {
                for (p in 1 .. N - 1) {
                    EvaluateEqualityClauses(x, p, res[p - 1]);
                }

                X(y);
                (ControlledOnInt(0, X))(res, y);

                for (p in 1 .. N - 1) {
                    EvaluateEqualityClauses(x, p, res[p - 1]);
                }
            }
        }
        adjoint auto;
    }   
}

// namespace Solution {
//     open Microsoft.Quantum.Primitive;
//     open Microsoft.Quantum.Canon;
//     open Microsoft.Quantum.Extensions.Diagnostics;

//     operation Solve (qs : Qubit[]) : Unit {
//         H(qs[0]);
//         H(qs[1]);
//         let x = Measure([PauliZ, PauliX], qs);
//         Message($"{x}");
//     }

//     operation Tester() : Unit {
//         using(qbs=Qubit[2]) {
//             Solve(qbs);
//             DumpMachine();
//             ResetAll(qbs);   
//         }
//     }
// }