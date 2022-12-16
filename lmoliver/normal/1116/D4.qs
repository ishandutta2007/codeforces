namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;

	operation Solve (qs : Qubit[]) : Unit {
		let N=Length(qs);
		Controlled MultiX([qs[0]],qs[1..N-1]);
		H(qs[0]);
		Controlled MultiX([qs[0]],qs[1..N-1]);
		(ControlledOnInt(0,MultiX))([qs[N-1]],qs[0..N-2]);
		for(i in N-2..-1..1){
			X(qs[i]);
			(ControlledOnInt(0,X))(qs[0..i-1],qs[i]);
		}
		(ControlledOnInt(0,MultiX))([qs[N-1]],qs[0..N-2]);
	}
}