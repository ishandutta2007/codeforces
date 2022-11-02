import java.util.*

fun main(args: Array<String>){
	val cin=Scanner(System.`in`);

	var N=cin.nextInt();
	var ans=Array<Int>(N){i->0};
	
	var A=Array<Int>(N){i->0};
	for(i in 0..N-1)A[i]=cin.nextInt();
	
	for(i in N-1 downTo 0){
	    var t=N-1-i;
	    for(j in t-1 downTo A[i]){
	        ans[j+1]=ans[j];
	    }
	    ans[A[i]]=i+1;
	}
	
	for(e in ans)print("${e} ");
	println("");
}