import java.util.ArrayDeque

fun run() {
    val (na,nb,m) = readLine()!!.split(" ").map{it.toInt()}
    val cnt = readLine()!!.split(" ").map{it.toInt()}
    val adj = Array(na+nb) {mutableListOf<Int>()}
    repeat(m) { 
        val (a,b) = readLine()!!.split(" ").map{it.toInt()-1}
        adj[a].add(na+b)
        adj[na+b].add(a)
    }
    val done = Array(na+nb) {false}
    val q = ArrayDeque<Int>()
    var ret=0
    for(i in 0 until na) if(!done[i]) {
        q.addLast(i)
        done[i]=true
        var mincnt=cnt[i]
        var v=0; var e=0
        while(q.isNotEmpty()) {
            val at=q.removeFirst()
            ++v; if(at<na) e+=adj[at].size
            if(at<na) mincnt=minOf(mincnt,cnt[at])
            for(to in adj[at]) if(!done[to]) { done[to]=true; q.addLast(to); }
        }
        if(e==v-1) ret+=mincnt
    }
    println(ret)
}

fun main() {
    run()
}