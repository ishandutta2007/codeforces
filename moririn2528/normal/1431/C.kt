//var list= readLine()!!.split(" ").map(String::toInt)
import kotlin.math.*
fun solve(){
    val (n,m) = readLine()!!.split(" ").map(String::toInt)
    var list= readLine()!!.split(" ").map(String::toInt)
    var s :Int = 0;
    var a=0
    var b=0
    for(i in 0 until n){
        a=0
        for(j in 1 .. (n-i)/m) {
            a += list[i + j - 1]
        }
        s=max(s,a)
    }
    println(s);
}

fun main(){
    val n = readLine()!!.toInt()
    for(i in 1..n){
        solve()
    }
}