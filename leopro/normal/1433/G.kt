import java.util.*

inline class Edge(private val p: Pair<Int, Int>) : Comparable<Edge> {
    override operator fun compareTo(other: Edge) = if (p.first == other.p.first) p.second.compareTo(other.p.second)
    else p.first.compareTo(other.p.first)

    constructor(x: Int, y: Int) : this(Pair(x, y))

    fun index() = p.second
    fun weight() = p.first
}

fun main() {
    val (n, m, k) = readInts()
    val edges = Array(n) { MutableList(0) { Edge(0, 0) } }
    val edgesList = Array(m) { Pair(0, 0) }
    for (j in 0 until m) {
        val (x, y, w) = readInts().map { it - 1 }
        edges[x].add(Edge(w + 1, y))
        edges[y].add(Edge(w + 1, x))
        edgesList[j] = Pair(x, y)
    }
    val routes = Array(k) { readInts().map{it - 1}.toPair() }

    val matrix = Array(n) { IntArray(n) { 1_000_000_000 } }
    for (start in matrix.indices) {
        val distance = matrix[start]
        distance[start] = 0
        val dijkstra = PriorityQueue<Edge>()
        dijkstra.add(Edge(0, start))
        while (!dijkstra.isEmpty()) {
            val lowest = dijkstra.poll()
            if (lowest.weight() != distance[lowest.index()]) continue
            for (next in edges[lowest.index()]) {
                if (distance[next.index()] > lowest.weight() + next.weight()) {
                    distance[next.index()] = lowest.weight() + next.weight()
                    dijkstra.add(Edge(distance[next.index()], next.index()))
                }
            }
        }
    }
    var ans = 1_000_000_000
    for (e in edgesList) {
        var cur = 0
        for (route in routes) {
            val minCost = minOf(matrix[route.first][route.second],
                    matrix[route.first][e.first] + matrix[e.second][route.second],
                    matrix[route.second][e.first] + matrix[e.second][route.first])
            cur += minCost
        }
        ans = minOf(ans, cur)
    }
    println(ans)
}

fun <T> List<T>.toPair() = Pair(this.component1(), this.component2())
fun readLong() = readLine()!!.toLong()
fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()