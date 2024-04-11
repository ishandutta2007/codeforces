namespace Solution
{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            mutable res=new Int[N];
            using(qubits = Qubit[N + 1])
            {
                X(qubits[N]);
                ApplyToEach(H, qubits);
                Uf(qubits[0..N-1],qubits[N]);
                ApplyToEach(H, qubits[0..N-1]); 
                for (idx in 0..N-1)
                {
                    if(MResetZ(qubits[idx])==One)
                    {
                        set res[idx] = 1;
                    }
                    else
                    {
                        set res[idx] = 0;
                    }
                }
                Reset(qubits[N]);
            }
            return res;
        }
    }
}