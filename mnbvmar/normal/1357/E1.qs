namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        let num_apps = p % 4;
        for (i in 1 .. num_apps) {
            QFTLE(inputRegister);
        }
    }
}