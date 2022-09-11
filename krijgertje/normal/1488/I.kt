import java.util.Queue
import java.util.LinkedList

fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

class MF(val n: Int) {
    val ghead = IntArray(n){-1}
    val gnxt = mutableListOf<Int>()
    val gto = mutableListOf<Int>()
    val gcap = mutableListOf<Int>()
    
    

    fun addEdge(a: Int, b: Int) {
        gnxt.add(ghead[a]); ghead[a] = gnxt.lastIndex; gto.add(b); gcap.add(1)
        gnxt.add(ghead[b]); ghead[b] = gnxt.lastIndex; gto.add(a); gcap.add(1)
    }

    fun maxFlow(s: Int, t: Int):Int {
        var d = IntArray(n){Int.MAX_VALUE}
        var cur = IntArray(n){0}

        fun dfs(at: Int, lim: Int): Int {
            if(at == t) return lim
            if(d[at] >= d[t]) return 0
            var ret = 0
            while(cur[at] != -1) {
                val to = gto[cur[at]]; val cap = gcap[cur[at]];
                if(d[to]==d[at]+1 && cap > 0) {
                    val now = dfs(to, minOf(cap,lim-ret))
                    ret += now
                    gcap[cur[at]] -= now
                    gcap[cur[at] xor 1] += now
                    if(lim == ret) break
                }
                cur[at] = gnxt[cur[at]]
            }
            return ret
        }
        
        var ret = 0
        while(true) {
            d = IntArray(n){Int.MAX_VALUE}
            val q: Queue<Int> = LinkedList<Int>()
            fun relax(at: Int, dist: Int) {
                if(d[at] != Int.MAX_VALUE) return
                d[at] = dist; q.add(at)
            }
            relax(s,0)
            while(!q.isEmpty() && d[t]==Int.MAX_VALUE) {
                val at = q.remove()
                var x = ghead[at]
                while(x != -1) {
                    val to = gto[x]
                    if(gcap[x] > 0 && d[to] == Int.MAX_VALUE) relax(to,d[at]+1)
                    x = gnxt[x]
                }
            }
            if(d[t] == Int.MAX_VALUE) return ret
            cur = ghead.copyOf()
            ret += dfs(s, Int.MAX_VALUE)
        }
    }
}

fun run() {
    val (n,m,nmage) = readInts()
    val adj = Array(n, {mutableListOf<Pair<Int,Int>>()})
    for(i in 0..m-1) {
        val (a,b) = readInts().map{it-1}
        adj[a].add(Pair(b,i))
        adj[b].add(Pair(a,i))
    }
    val d = Array(n, {Int.MAX_VALUE})
    val q: Queue<Int> = LinkedList<Int>()
    fun relax(at: Int, dist: Int) {
        if(d[at] != Int.MAX_VALUE) return
        d[at] = dist; q.add(at)
    }
    relax(0,0)
    while(!q.isEmpty()) {
        val at = q.remove()
        for((to,id) in adj[at]) relax(to,d[at]+1)
    }
    var nid = 0
    val sid = nid++
    val tid = nid++
    val eid = Array(m,{nid++})
    val vid = Array(n,{nid++})
    val g = MF(nid)
    for(at in 0..n-1) for((to,id) in adj[at]) if(d[to]>d[at]) {
        if(d[at]%2==0) {
            g.addEdge(sid,eid[id])
            g.addEdge(eid[id],vid[at])
            g.addEdge(eid[id],vid[to])
        } else {
            g.addEdge(vid[at],eid[id])
            g.addEdge(vid[to],eid[id])
            g.addEdge(eid[id],tid)
        }
    }
    println(minOf(nmage,g.maxFlow(sid,tid)))
}

fun main() {
    run()
}