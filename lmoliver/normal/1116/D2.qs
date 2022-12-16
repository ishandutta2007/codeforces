namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
		let N=Length(qs);
		for(i in 0..N-1){
			MultiX(qs[i+1..N-1]);
			for(j in 0..i-1){
				Controlled H(qs[i..N-1],qs[j]);
			}
			MultiX(qs[i+1..N-1]);
		}
    }
}