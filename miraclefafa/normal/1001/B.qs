namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[], index : Int) : () {
        body {
            if (index==0) {
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            } elif (index==1) {
                X(qs[0]);
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            } elif (index==2) {
                X(qs[1]);
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            } else {
                X(qs[0]);
                X(qs[1]);
                H(qs[0]);
                CNOT(qs[0],qs[1]);
            }
        }
    }
}