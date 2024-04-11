namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	operation Solve_period(x : Qubit[], y : Qubit,p:Int):Unit{
		body(...){
			let N=Length(x);
			let q=N-p;
			for(i in 0..q-1){
				CNOT(x[i+p],x[i]);
			}
			(ControlledOnInt(0,X))(x[0..q-1],y);
			for(i in q-1..-1..0){
				CNOT(x[i+p],x[i]);
			}
		}
		adjoint auto;
	}
	operation Solve (x : Qubit[], y : Qubit) : Unit {
		body (...) {
			let N=Length(x);
			X(y);
			using (r = Qubit[N-1]) {
				for(i in 1..N-1){
					Solve_period(x,r[i-1],i);
				}
				(ControlledOnInt(0,X))(r,y);
				for(i in 1..N-1){
					Solve_period(x,r[i-1],i);
				}
			}
		}
		adjoint auto;
	}
}