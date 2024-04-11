namespace Solution {
	open Microsoft.Quantum.Primitive;
	open Microsoft.Quantum.Canon;
	operation Flips(qs : Qubit[],bits:Bool[]) : Unit {
		body (...) {
			let N=Length(qs);
			for(i in 0..N-1){
				if(bits[i]){
					X(qs[i]);
				}
			}
		}
		adjoint auto;
		controlled auto;
		controlled adjoint auto;
	}
	operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
		let N=Length(qs);
		using (id = Qubit[2]) {
			H(id[0]);
			H(id[1]);
			(ControlledOnBitString([false,false],Flips))(id,(qs,bits[0]));
			(ControlledOnBitString([false,true],Flips))(id,(qs,bits[1]));
			(ControlledOnBitString([true,false],Flips))(id,(qs,bits[2]));
			(ControlledOnBitString([true,true],Flips))(id,(qs,bits[3]));
			Flips(qs,bits[0]);
			(ControlledOnInt(0,Flips))(qs,(id,[false,false]));
			Flips(qs,bits[0]);
			Flips(qs,bits[1]);
			(ControlledOnInt(0,Flips))(qs,(id,[false,true]));
			Flips(qs,bits[1]);
			Flips(qs,bits[2]);
			(ControlledOnInt(0,Flips))(qs,(id,[true,false]));
			Flips(qs,bits[2]);
			Flips(qs,bits[3]);
			(ControlledOnInt(0,Flips))(qs,(id,[true,true]));
			Flips(qs,bits[3]);
		}
	}
}