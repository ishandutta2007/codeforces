namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
       using (qs = Qubit[2]){
        X(qs[0]);
        X(qs[1]);
        unitary(qs);
        let res=M(qs[0]);
        ResetAll(qs);
        if (res==Zero){
            return 1;
        }
        else{
            return 0;
        }
        }
    }
}