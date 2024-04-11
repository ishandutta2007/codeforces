namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            let res = M (q);
            if (res==Zero) {
                return 1;
            } else {
                return -1;
            }
        }
    }
}