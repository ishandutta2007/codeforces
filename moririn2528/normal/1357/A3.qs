// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable s=0;
		using(q=Qubit()){
			unitary(q);
			X(q);
			unitary(q);
			if(M(q)==One){
				set s=1;
			}
			Reset(q);
		}
		return s;
    }
}