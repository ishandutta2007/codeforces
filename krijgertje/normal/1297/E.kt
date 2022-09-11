import kotlin.math.*

class Node(val id:Int) {
    val adj=mutableListOf<Node>()
    var deg=0
    var alive=true
}

fun run() {
    val (n,want)=readLine()!!.split(" ").map{it.toInt()}
    val nodes=Array<Node>(n){Node(it)}
    repeat(n-1) { val (a,b)=readLine()!!.split(" ").map{nodes[it.toInt()-1]}; a.adj.add(b); b.adj.add(a) }
    for(u in nodes) u.deg=u.adj.size
    var have=0
    val q=mutableListOf<Node>()
    for(u in nodes) if(u.deg<=1) { ++have; q.add(u) }
    if(have<want) { println("No"); return }
    println("Yes")
    while(have>want) {
        val u=q.last(); q.removeAt(q.lastIndex)
        u.alive=false; --have;
        for(v in u.adj) if(v.alive) {
            --v.deg;
            if(v.deg==1) { ++have; q.add(v) }
        }
    }
    val keep=nodes.filter{it.alive}
    println(keep.size)
    println(keep.map{it.id+1}.joinToString(" "))
}

fun main() {
    val ncase=readLine()!!.toInt()
    for(i in 1..ncase) run()
}