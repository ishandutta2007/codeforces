// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Measurement;

    operation Solve (qs : Qubit[]) : Unit {
		mutable flag=0;
		using(q=Qubit()){
			repeat{
				ResetAll(qs);
				Reset(q);
				ApplyToEach(H,qs);
				Controlled X(qs,q);
			}until(M(q)==Zero)
			fixup{}
		}
    }
}