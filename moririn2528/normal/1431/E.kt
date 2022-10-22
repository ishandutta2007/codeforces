//var list= readLine()!!.split(" ").map(String::toInt)
import kotlin.math.*

fun solve(){
    val n = readLine()!!.toInt()
    var list1= readLine()!!.split(" ").map(String::toInt)
    var list2= readLine()!!.split(" ").map(String::toInt)
    var s :Int = 0;
    var a=0
    var b=0
    var ls :MutableList<Int> = MutableList(n){0}
    var la :MutableList<Pair<Int,Int>> = list1.zip(List<Int>(n){it}).toMutableList()
    var lb :MutableList<Pair<Int,Int>> = list2.zip(List<Int>(n){it}).toMutableList()
    la.sortBy { it.first }
    lb.sortBy { it.first }
    b=0;
    for(i in 0 until n){
        a=10000000;
        for(j in 0 until n){
            a=min(a,abs(la[j].first-lb[(i+j)%n].first));
        }
        if(b<a){
            b=a;s=i;
        }
    }
    for(i in 0 until n){
        ls[la[i].second]=lb[(i+s)%n].second+1;
    }
    println(ls.joinToString(separator = " "))
}

fun main(){
    val n = readLine()!!.toInt()
    for(i in 1..n){
        solve()
    }
}