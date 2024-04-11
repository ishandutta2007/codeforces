// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

	operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
        using(qubit=Qubit()){
            let res=M(qubit);
			Reset(qubit);
			unitary(qubit);
            let res2=M(qubit);
			Reset(qubit);
			mutable s=1;
			if(res==res2){
				set s=0;
			}
			return s;
        }
    }
}