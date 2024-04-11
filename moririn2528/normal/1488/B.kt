//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve(){
    val (n,m) = readLine()!!.split(" ").map{it.toInt()}
    val sa=readLine()!!;
    var a=0;
    var cnt=0;
    var s=0;
    for(i in 0..n-1){
        if(sa[i]=='(')a++;
        else a--;
        if(a==0)cnt++;
    }
    cnt+=m;
    println(min(cnt,n/2));
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 0..n-1){
        solve();
    }
}