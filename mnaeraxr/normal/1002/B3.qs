namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            H(qs[1]);

            let x0 = M(qs[0]);
            let x1 = M(qs[1]);

            mutable v0 = 0;
            mutable v1 = 0;

            if (x0 == One){
                set v0 = 1;
            }

            if (x1 == One){
                set v1 = 1;
            }

            return 2* v0 + v1;
        }
    }
}