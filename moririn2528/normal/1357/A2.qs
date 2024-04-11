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
			if(M(q[1])==Zero){
				set s=1;
			}elif(M(q[0])==Zero){
				set s=2;
			}else{
				Reset(q[0]);Reset(q[1]);
				X(q[0]);
				unitary(q);
				if(M(q[0])==Zero){
					set s=3;
				}
			}
			Reset(q[0]);Reset(q[1]);
		}
		return s;
    }
}