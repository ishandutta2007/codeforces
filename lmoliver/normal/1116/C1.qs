namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
			let N=Length(x);
			MultiX(x[0..2..N-1]);
			Controlled X(x,y);
			MultiX(x);
			Controlled X(x,y);
			MultiX(x);
			MultiX(x[0..2..N-1]);
        }
        adjoint auto;
    }
}