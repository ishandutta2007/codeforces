namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0],qs[1]);
            H(qs[0]);
            let p1=M(qs[0]);
            let p2=M(qs[1]);
            mutable index=0;
            if (p1==One) {
                set index = index + 1;
            }
            if (p2==One) {
                set index = index + 2;
            }
            return index;
        }
    }
}