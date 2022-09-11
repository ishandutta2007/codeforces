import kotlin.math.*

class Cartoon(var l:Int,var r:Int) {}

fun run() {
    val n=readLine()!!.toInt()
    val cartoons = List<Cartoon>(n) { val (l,r)=readLine()!!.split(" ").map{it.toInt()}; Cartoon(l,r+1); }
    val tt=mutableListOf<Int>()
    for(c in cartoons) { tt.add(c.l); tt.add(c.r); }
    val t=tt.sorted().distinct() 
    //println(t)
    val cnt=IntArray(t.size)
    for(c in cartoons) { ++cnt[t.binarySearch(c.l)]; --cnt[t.binarySearch(c.r)]; }
    for(i in 0 until cnt.size-1) cnt[i+1]+=cnt[i]
    //println(cnt.joinToString(" "))
    for(i in 0 until cnt.size) if(cnt[i]==1) { println(t[i]); return; }
    println(-1)
 }

fun main() {
    val ncase=readLine()!!.toInt()
    for(i in 1..ncase) run()
}