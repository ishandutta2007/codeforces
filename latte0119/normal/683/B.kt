import java.util.*

fun main(args: Array<String>){
	val cin=Scanner(System.`in`);

	val N=cin.nextInt();
    var S=Array<String>(N,{i->""});
    var H=Array<Int>(N,{i->0});
	for(i in 0..N-1){
		S[i]=cin.next();
		H[i]=cin.nextInt();
	}
	
	for(i in 0..N-1){
	    for(j in i+1..N-1){
	        if(H[i]>H[j]){
	            var s=S[i];S[i]=S[j];S[j]=s;
	            var h=H[i];H[i]=H[j];H[j]=h;
	        }
	    }
	}
	
	for(i in 0..N-1){
	    println("${S[i]}");
	}
}