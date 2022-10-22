// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
		mutable s=0;
		using(q=Qubit[2]){
			X(q[0]);X(q[1]);
			unitary(q);
			let res=M(q[0]);
			if(res==Zero){
				set s=1;
			}
			Reset(q[0]);Reset(q[1]);
		}
		return s;
    }
}