import java.util.*

fun main(args: Array<String>){
	val cin=Scanner(System.`in`);

	var q=cin.nextInt();

	while(q--!=0){
	    var H=cin.nextInt();
	    var W=cin.nextInt();
	    var P=cin.nextInt();
	    
	    var ok=0;
	    for(i in 1..H){
	        if(P%i!=0)continue;
	        if(P/i>W)continue;
	        ok=1;
	    }
	    println(if(ok==1)"Yes" else "No");
	}
}