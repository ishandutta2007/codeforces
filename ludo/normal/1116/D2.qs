namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve(qs : Qubit[]) : Unit {
        let n = Length(qs);

        for (i in 0 .. n-2) {
             (Controlled H)([ qs[n-1] ], qs[i]);
        }

        // X(qs[n-1]);
        // for (i in 0 .. n-3) {
        //     (Controlled H)(qs[n-2 .. n-1], qs[i]);
        // }
        // X(qs[n-1]);

        // biggest transformation:
        if (n >= 3) {
            for (j in 1 .. n-2) {
                for (i in j+1 .. n-1) {
                    X(qs[i]);
                }
                for (i in 0 .. j-1) {
                    (Controlled H)(qs[j .. n-1], qs[i]);
                }
                for (i in j+1 .. n-1) {
                    X(qs[i]);
                }
            }
        }
    }
}