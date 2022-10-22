namespace Solution{
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Intrinsic;

    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        mutable ans = 0;
        using ((q1,q2) = (Qubit(),Qubit())){
            Set(One,q1);
            Set(Zero,q2);
            unitary([q1,q2]);
            let res = M(q2);
            if(res == One){
                set ans = 1;
            }
            Set(Zero,q1);
            Set(Zero,q2);
        }
        set ans = 1 - ans;
        return ans;
    }
}