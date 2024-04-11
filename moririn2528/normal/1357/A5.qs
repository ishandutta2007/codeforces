// : dotnet run
namespace Solution {

    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Math;
	open Microsoft.Quantum.Convert;

    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        // your code here
		mutable cnt=0;
		mutable a=10.0;
		for(i in 0 .. 100){
			mutable b=Floor(theta*IntAsDouble(i)/PI());
			if(b%2==0){
				set b = b+1;
			}
			let c=AbsD(IntAsDouble(b)*PI()-theta*IntAsDouble(i));
			if(c<a){
				set a=c;
				set cnt=i;
			}
		}
		using(q=Qubit()){
			for(i in 0 .. cnt-1){
				unitary(q);
			}
			let res=M(q);
			Reset(q);
			if(res==Zero){
				return 0;
			}else{
				return 1;
			}
		}
    }
}