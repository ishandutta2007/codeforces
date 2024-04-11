namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let v = M(q);

            if (v == Zero)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}