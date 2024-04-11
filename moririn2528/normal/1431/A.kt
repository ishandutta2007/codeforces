//var list= readLine()!!.split(" ").map(String::toInt)
import kotlin.math.*
fun solve(){
    val n = readLine()!!.toInt()
    var list: MutableList<Long> = readLine()!!.split(" ").map(String::toLong).toMutableList()
    list.sort()
    var s :Long = 0;
    for(i in 1..n){
        s=max(s,(n-i+1)*list[i-1]);
    }
    println(s);
}

fun main(){
    val n = readLine()!!.toInt()
    for(i in 1..n){
        solve()
    }
}