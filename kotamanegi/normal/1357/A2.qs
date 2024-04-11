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
            let Q1 = M(q1);
            let Q2 = M(q2);
            if(Q2 == One){
                if(Q1 == One){
                    set ans = 1;
                }else{
                    set ans = 3;
                }
            }
            Set(Zero,q1);
            Set(Zero,q2);
        }
        
        using ((q1,q2) = (Qubit(),Qubit())){
            Set(Zero,q1);
            Set(One,q2);
            unitary([q1,q2]);
            let Q1 = M(q1);
            let Q2 = M(q2);
            if(Q1 == One){
                if(Q2 == One){
                    set ans = 2;
                }else{
                    set ans = 3;
                }
            }
            Set(Zero,q1);
            Set(Zero,q2);
        }
        return ans;
    }
}