namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;

    function NumApplications (angle : Double) : Int {
        return Round(PI() / angle);
    }

    operation Apply (num_apps : Int, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            for (i in 1..num_apps) {
                unitary(q);
            }
            let ans = M(q) == One ? 1 | 0;
            Reset(q);
            return ans;
        }
    }

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        let num_apps = NumApplications(theta);
        let num_tries = 5;
        mutable num_ones = 0;
        for (id in 1..num_tries) {
            set num_ones = num_ones + Apply(num_apps, unitary);
        }
        return (num_ones > 0) ? 1 | 0;
    }
}