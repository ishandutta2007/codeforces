namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable result = new Result[N];

            using(qubits = Qubit[N + 1]) {
                X(qubits[N]);

                ApplyToEach(H, qubits);

                Uf(qubits[0..(N-1)], qubits[N]);

                ApplyToEach(H, qubits[0..(N - 1)]);

                for (i in 0..(N-1)) {
                    set result[i] = MResetZ(qubits[i]);
                }

                Reset(qubits[N]);
            }

            mutable answer = new Int[N];

            for (i in 0..N-1)
            {
                if (result[i] == One)
                {
                    set answer[i] = 1;
                }
                else
                {
                    set answer[i] = 0;
                }
            }

            return answer;
        }
    }

    operation Test() : ()
    {
        body
        {
        }
    }
}