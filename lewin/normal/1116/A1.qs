namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation CSWAP(c: Qubit, x: Qubit, y: Qubit) : Unit {
        CCNOT(c,x,y);
        CCNOT(c,y,x);
        CCNOT(c,x,y);
    }
    operation t1(ts: Qubit[]) : Unit {
        mutable n=1;
        X(ts[0]);
        for(k in 0..7) {
            if(n<Length(ts)) {

            using(qq=Qubit[1]) {
                let q=qq[0];
                H(q);
                for(i in 0..n-1) {
                    CSWAP(q,ts[i],ts[i+n]);
                }
                for(i in 0..n-1) {
                    CNOT(ts[i+n],q);
                }
            }
            set n=n*2;
            }
        }
    }

    operation Solve (qs : Qubit[]) : Unit {
        using(ts=Qubit[4]) {
            repeat {
                t1(ts);
            } until (M(ts[3]) == Zero)
            fixup {
                ResetAll(ts);
            }
            CNOT(ts[1], qs[0]);
            CNOT(ts[2], qs[1]);
            CNOT(qs[0], ts[1]);
            CNOT(qs[0], ts[0]);
            CNOT(qs[1], ts[2]);
            CNOT(qs[1], ts[0]);
            X(ts[0]);
        }
    }
}