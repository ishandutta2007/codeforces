namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	operation CRot(c:Qubit,x:Qubit[]):Unit{
		body(...){
			Controlled SWAP([c],(x[0],x[1]));
			Controlled SWAP([c],(x[1],x[2]));
		}
		adjoint auto;
	}
	operation Solve (x : Qubit[], y : Qubit) : Unit {
		body (...) {
			let N=Length(x);
			using(r=Qubit[3]){
				X(r[0]);
				for(q in x){
					CRot(q,r);
				}
				CNOT(r[0],y);
				for(q in x){
					CRot(q,r);
					CRot(q,r);
				}
				X(r[0]);
			}
		}
		adjoint auto;
	}
}