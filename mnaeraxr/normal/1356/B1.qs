namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Arrays;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        for (index in Length(register!) - 1..-1..0) {
            let control = Subarray(RangeAsIntArray(0..index-1), register!);
            Controlled X(control, register![index]);
        }
    }
}