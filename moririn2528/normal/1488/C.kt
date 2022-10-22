//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun calc(a:Int,b:Int,c:Int):Int{
    if(b<=c)return c-a;
    if(c<=a)return b-c;
    return min(c-a,b-c)+b-a;
}

fun solve(){
    val (n,x,y) = readLine()!!.split(" ").map{it.toInt()}
    var s=n*10;
    for(i in 1..n){
        s=min(s,max(calc(1,i,x),calc(i+1,n,y)));
        s=min(s,max(calc(1,i,y),calc(i+1,n,x)));
    }
    println(s);
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 0..n-1){
        solve();
    }
}