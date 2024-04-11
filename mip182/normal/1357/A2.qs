namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
       using (qs = Qubit[2]){
        X(qs[0]);
        X(qs[1]);
        unitary(qs);
        let res=M(qs[0]);
        let res1=M(qs[1]);
        ResetAll(qs);
        if (res==Zero){
            return 2;
        }
        else{
            if (res1==Zero){
            return 1;
            }
            else
            {
                 X(qs[1]);
                 unitary(qs);
                 let res11=M(qs[0]);
                 let res12=M(qs[1]);
                 ResetAll(qs);
                 if (res11==Zero)
                 {
                     return 0;
                 }
                 else
                 {
                     return 3;
                 }
            }
            
        }
        }
    }
}