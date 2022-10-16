namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable ghz = 0;

            let first = M(qs[0]);

            for (i in 1..Length(qs)-1){
                let value = M(qs[i]);

                if (value != first){
                    set ghz = 1;
                }
            }

            return ghz;
        }
    }
}