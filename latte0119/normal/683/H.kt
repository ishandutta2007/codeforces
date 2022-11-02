import java.util.*

fun gcd(a:Long,b:Long):Long{
    if(b==0.toLong())return a;
    return gcd(b,a%b);
}

fun main(args: Array<String>){
	val cin=Scanner(System.`in`);
    
    var N=cin.nextInt();
    var K:Long=cin.nextLong();
    var A=Array<Int>(N){i->0};
    for(i in 0..N-1)A[i]=cin.nextInt()-1;
    
    var ans=Array<Int>(N){i->-1};
    for(i in 0..N-1){
        if(ans[i]!=-1)continue;
        var a=i;
        var len:Long=0;
        while(true){
            len++;
            a=A[a];
            if(a==i)break;
        }
        len=K%len;
        var b=i;
        for(j in 0..len-1){
            b=A[b];
        }
        while(true){
            ans[b]=a;
            a=A[a];
            b=A[b];
            if(a==i)break;
        }
    }
    
    for(e in ans)print("${e+1} ");
    println("");
}