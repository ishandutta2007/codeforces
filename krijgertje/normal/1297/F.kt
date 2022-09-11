import kotlin.math.*
import java.util.PriorityQueue

class Movie(val l: Int,val r: Int,val id:Int) {}

fun run() {
    val (n,lim)=readLine()!!.split(" ").map{it.toInt()}
    val movies = List<Movie>(n) { val (l,r)=readLine()!!.split(" ").map{it.toInt()}; Movie(l,r,it); }.sortedBy{it.l}
    //println("n=$n"); for(m in movies) println("${m.l}..${m.r}")
    var day=movies[0].l; var at=0; val available=PriorityQueue<Movie>(compareBy{it.r})
    val visit=IntArray(n)
    var ret=0
    while(at<n||available.size>0) {
        if(available.size==0&&day<movies[at].l) day=movies[at].l
        while(at<n&&day>=movies[at].l) available.add(movies[at++])
        for(i in 0 until lim) {
            if(available.size==0) break
            val cur=available.remove()
            ret=max(ret,day-cur.r)
            visit[cur.id]=day
        }
        ++day
    }
    println(ret)
    println(visit.joinToString(" "))
}

fun main() {
    val ncase=readLine()!!.toInt()
    for(i in 1..ncase) run()
}