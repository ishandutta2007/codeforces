// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        using(qubit=Qubit[2]){
			let x=qubit[0];
			let y=qubit[1];
			R(PauliX,PI(),x);
            let res=M(x);
			Reset(x);

			R(PauliX,PI()/2.0,y);
			unitary(y);
			R(PauliX,PI()/2.0,y);
            let res2=M(y);
			Reset(y);
			
			mutable s=1;
			if(res==res2){
				set s=0;
			}
			return s;
        }
    }
}