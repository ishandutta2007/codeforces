namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            if (Random([1.;1.]) == 0)
            {
                let x = M(q);

                if (x == One)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                H(q);
                let x = M(q);

                if (x == One)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
        }
    }

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);

            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Test(times : Int, mode : Int) : (Int, Int){

        body
        {
            mutable zeros = 0;
            mutable ones = 0;

            using (qbits = Qubit[1]){
                let q = qbits[0];

                for (i in 1..times){
                    Set(Zero, q);

                    if (mode == 1)
                    {
                        H(q);
                    }

                    let value = Solve(q);

                    // let value = Random([1.;1.]);

                    if (value == 0){
                        set zeros = zeros + 1;
                    }

                    if (value == 1){
                        set ones = ones + 1;
                    }
                }

                Set(Zero, q);
            }

            return (zeros, ones);
        }
    }
}