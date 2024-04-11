// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        using(qubit=Qubit()){
			R(PauliY,PI()/2.0,qubit);

			unitary(qubit);
			unitary(qubit);
			R(PauliY,PI()/2.0,qubit);
            let res=M(qubit);
			Reset(qubit);
			
			mutable s=1;
			if(res==One){
				set s=0;
			}
			return s;
        }
    }
}