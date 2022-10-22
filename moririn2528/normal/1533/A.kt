//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve() {
    var (n,m) = readLine()!!.split(" ").map { it.toInt() };
    var s=0;
    for(i in 0 until n){
        var (a,b) = readLine()!!.split(" ").map { it.toInt() };
        if(a<=m && m<=b)s=max(s,b-m+1);
    }
    println(s);
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 1..n){
        solve();
    }
}