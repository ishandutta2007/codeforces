//val n = readLine()!!.toInt();
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve(){
    var n = readLine()!!.toInt();
    var (a,va) = readLine()!!.split(" ").map{it.toInt()};
    var (c,vc) = readLine()!!.split(" ").map{it.toInt()};
    var b = readLine()!!.toInt();
    println(max(vc-(c-b),va));
}


fun main(){
    var n = readLine()!!.toInt();
    for(i in 1..n){
        solve();
    }
}