namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Unit {
		let N=Length(qs);
		Controlled MultiX([qs[0]],qs[1..N-1]);
		H(qs[0]);
		Controlled MultiX([qs[0]],qs[1..N-1]);
	}
}