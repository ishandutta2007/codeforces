namespace Solution {
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable a = 0;
        using(x = Qubit[1]){
            unitary(x[0]);
            let measurement = M(x[0]);
            if(measurement==One){
                set a = 1;
            }
            ResetAll(x);
        }
        if(a==1){
            return 1;
        }else{
            return 0;
        }
    }
}