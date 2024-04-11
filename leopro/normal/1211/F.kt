class Edge(val next: Int, val n: Int)

fun main() {
    val n = readLine()!!.toInt()
    val kotlin = "kotlin"
    val graph = Array(kotlin.length) { mutableListOf<Edge>() }
    for (i in 0 until n) {
        val s = readLine()!!
        graph[(kotlin.indexOf(s.last()) + 1) % kotlin.length].add(Edge(kotlin.indexOf(s.first()), i + 1))
    }
    val eulerPath = mutableListOf<Int>()
    fun findEulerPath(cur: Int) {
        while (graph[cur].isNotEmpty()) {
            val edge = graph[cur].removeLast()
            findEulerPath(edge.next)
            eulerPath.add(edge.n)
        }
    }
    findEulerPath(0)
    println(eulerPath.joinToString(" "))
}