//var list= readLine()!!.split(" ").map(String::toInt)
import kotlin.math.*
fun solve(){
    val n = readLine()!!.toInt()
    var list= readLine()!!.split(" ").map(String::toInt)
    var s :Int = 0;
    var a=0
    var b=0
    var ls :MutableList<Int> = MutableList(n){0}
    var la :MutableList<Pair<Int,Int>> = list.zip(List<Int>(n){it+1}).toMutableList()
    la.sortBy { it.first }
    for(i in 0 until n) {
        a += la[i].first
        if (a >= n) break
        ls[a] = la[i].second
        //println("${a},${ls[a]}")
        b++
    }
    for(j in 0 until n){
        if(ls[j]!=0)continue
        ls[j]=la[b].second
        b++
    }
    println(ls.joinToString(separator = " "));
}

fun main(){
    val n = readLine()!!.toInt()
    for(i in 1..n){
        solve()
    }
}