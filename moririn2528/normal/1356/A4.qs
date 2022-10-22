// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;

	operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        using(qubit=Qubit[2]){

			unitary(qubit);
            let res=M(qubit[1]);
			ResetAll(qubit);
			
			mutable s=1;
			if(res==One){
				set s=0;
			}
			return s;
        }
    }
}