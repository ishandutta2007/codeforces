namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set(desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if(desired != current){
                X(q1);
            }
        }
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let A = Controlled(X);
            let n = Length(qs);
            if(n == 1){
                X(qs[0]);
            }
            else {
                let m = n/2;
                Solve(qs[0..m-1]);
                H(qs[m]);
                for(i in 1..m-1){
                    A([qs[i];qs[m]],qs[i+m]);
                }
                for(i in m+1..n-1){
                    CNOT(qs[i],qs[m]);
                }
                for(i in 0..m-1){
                    CNOT(qs[i+m],qs[i]);
                }
            }
        }
    }
}