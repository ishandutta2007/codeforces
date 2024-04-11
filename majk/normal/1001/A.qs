namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            if (sign == -1) {
                X(q);
            }
            H(q);
        }
    }

    operation SolveTest () : ()
    {
        body
        {
            using (qubits = Qubit[2])
            {
                Solve(qubits[0], 1);
                //Solve(qubits[1], -1);
            }
        }
    }
}