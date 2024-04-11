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
        using (qbit = Qubit()){
            H(qbit);
            unitary(qbit);
            unitary(qbit);
            let res = MResetX(qbit);
            if(res == Zero){
                set ans = 1;
            }
            Set(Zero,qbit);
        }
        set ans = 1 - ans;
        return ans;
    }
}