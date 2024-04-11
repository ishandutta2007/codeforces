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
            for(i in 0..N-1)
            {
                set res[i]=0;
            }
            using(qubits = Qubit[N + 1])
            {
                Uf(qubits[0..N-1],qubits[N]);
                if(N%2==1)
                {
                    X(qubits[N]);
                }
                if(M(qubits[N])==One)
                {
                    set res[0]=1;
                }
                ResetAll(qubits);
            }
            return res;
        }
    }
}