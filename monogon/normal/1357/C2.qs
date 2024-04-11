namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let n = Length(qs);
        mutable flag = false;
        repeat {
            using(q = Qubit()) {
                for(i in 0..n-1) {
                    Reset(qs[i]);
                    H(qs[i]);
                    CNOT(qs[i], q);
                }
                let r = M(q);
                if((r == One) == (parity == 1)) {
                    set flag = true;
                }
                Reset(q);
            }
        }until(flag);
    }
}