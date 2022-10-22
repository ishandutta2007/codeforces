//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt();
    var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
    for(i in 0 until n-1){
        if((list[i]+list[i+1])%2==0){
            println("YES");
            return;
        }
    }
    println("NO");
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 1..n){
        solve();
    }
}