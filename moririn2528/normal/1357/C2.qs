// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Convert;
	open Microsoft.Quantum.Measurement;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        // your code here
		using(q=Qubit()){
			mutable a=0;
			repeat{
				for(i in 0 .. Length(qs)-1){
					H(qs[i]);
					CNOT(qs[i],q);
				}
				let res=M(q);
				if(res==One){
					set a=1;
				}else{
					set a=0;
				}
			}until(a==parity)
			fixup{
				Reset(q);
				ResetAll(qs);
			}
			Reset(q);
		}
    }
}