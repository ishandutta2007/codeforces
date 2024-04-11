namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable answer = 0;
            for (i in 0..Length(qs) - 1){
                let x = M(qs[i]);

                if (x == One){
                    set answer = 1;
                }
            }
            return answer;
        }
    }
}