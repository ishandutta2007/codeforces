namespace Solution{
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Intrinsic;

    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using (q1 = Qubit()){
            Set(Zero,q1);
            H(q1);
            unitary(q1);
            H(q1);
            unitary(q1);
            let hoge = M(q1);
            if(hoge == One){set ans = 1;}
            Set(Zero,q1);
        }
        return ans;
    }
}