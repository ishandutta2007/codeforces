fun main() {
    val (n1, n2, m) = readLine()!!.split(' ').map { it.toInt() }
    val k = readLine()!!.split(' ').map { it.toInt() } // size == n1
    val map = MutableList(n2) { mutableListOf<Int>() }
    repeat(m) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() - 1 }
        map[y].add(x)
    }
    val invGraph = mutableListOf<MutableList<Int>>()
    val cost = mutableListOf<Int>()
    for (i in 0 until n2) {
        repeat(map[i].size) {
            invGraph.add(map[i])
            cost.add(if (it == 0) map[i].minOf { k[it] } else 0)
        }
    }
    val graph = List(n1) { mutableListOf<Int>() }
    for (i in invGraph.indices) {
        for (j in invGraph[i]) {
            graph[j].add(i)
        }
    }
    println(minPerfectMatching(graph, cost))
}

fun minPerfectMatching(graph: List<MutableList<Int>>, cost: MutableList<Int>): Int {
    val minCost = IntArray(graph.size) { Int.MAX_VALUE }
    val visited = BooleanArray(graph.size)
    val pair = IntArray(cost.size) { -1 }

    fun calculate(cur: Int): Int {
        if (visited[cur]) return minCost[cur]
        visited[cur] = true
        for (next in graph[cur]) {
            if (pair[next] == -1) {
                minCost[cur] = minOf(minCost[cur], cost[next])
            } else {
                minCost[cur] = minOf(minCost[cur], calculate(pair[next]))
            }
        }
        return minCost[cur]
    }

    fun connect(cur: Int) {
        for (next in graph[cur]) {
            val friend = pair[next]
            if (friend == -1 && minCost[cur] == cost[next]) {
                pair[next] = cur
                return
            }
            if (friend != -1 && minCost[friend] == minCost[cur]) {
                pair[next] = cur
                minCost[cur] = Int.MAX_VALUE
                connect(friend)
                return
            }
        }
    }

    for (i in graph.indices) {
        minCost.fill(Int.MAX_VALUE)
        visited.fill(false)
        calculate(i)
        connect(i)
    }
    return pair.indices.filter { pair[it] != -1 }.sumOf { cost[it] }
}