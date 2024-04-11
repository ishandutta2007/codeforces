import kotlin.math.*

fun main() {
    val (n,lim)=readLine()!!.split(" ").map{it.toInt()}
    val a=readLine()!!.split(" ").map{it.toInt()}
    var mx=0; var mn=0; var cur=0;
    for(x in a) { cur+=x; mx=max(mx,cur); mn=min(mn,cur); }
    val need=mx-mn
    println(max(0,lim-need+1))
}