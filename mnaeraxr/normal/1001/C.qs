namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            H(qs[0]);

            for (index in 1 .. Length(qs) - 1) {
                CNOT(qs[0], qs[index]);
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

    operation Experiment(count : Int, size : Int) : Int
    {
        body
        {
            mutable allAgree = 0;

            using (qubits = Qubit[size])
            {
                for (test in 1..count)
                {
                    for (index in 0..size-1)
                    {
                        Set(Zero, qubits[index]);
                    }

                    Solve(qubits);

                    let v = M(qubits[0]);
                    mutable ok = true;

                    for (index in 0..size-1){
                        let t = M(qubits[index]);
                        if (t != v){
                            set ok = false;
                        }
                    }

                    if (ok){
                        set allAgree = allAgree + 1;
                    }
                }

                for (index in 0..size-1)
                {
                    Set(Zero, qubits[index]);
                }
            }

            return (allAgree);
        }
    }
}