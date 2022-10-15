class DSU(var components: Int) {
    private val parent = IntArray(components) { it }
    val size = IntArray(components) { 1 }

    fun component(x: Int): Int = if (parent[x] == x) x else component(parent[x]).also { parent[x] = it }

    fun connected(u: Int, v: Int) = component(u) == component(v)

    fun unite(x: Int, y: Int) {
        val a = parent[x]
        val b = parent[y]
        if (a == b) return
        components--
        if (size[a] < size[b]) {
            parent[a] = b
            size[b] += size[a]
        } else {
            parent[b] = a
            size[a] += size[b]
        }
    }

}

data class Edge(val u: Int, val v: Int, val cost: Long) : Comparable<Edge> {
    override fun compareTo(other: Edge) = compareValuesBy(this, other, { it.cost }, { it.u }, { it.v })
}

fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
    val offers = List(n) { mutableListOf<Edge>() }
    repeat(m) {
        val (x, y, w) = readLine()!!.split(' ').map { it.toLong() }
        val u = x.toInt() - 1
        val v = y.toInt() - 1
        offers[u].add(Edge(u, v, w))
        offers[v].add(Edge(v, u, w))
    }
    val dsu = DSU(n)
    fun processed(e: Edge) = Edge(dsu.component(e.u), dsu.component(e.v), e.cost)
    val components = MutableList(n) { mutableListOf(it) }
    val indices = a.indices.sortedBy { a[it] }.toIntArray()
    var ans = 0L
    while (dsu.components > 1) {
        val edges = mutableListOf<Edge>()
        for (cmp in components.indices) {
            if (components[cmp].isEmpty()) continue
            val minOut = indices.find { !dsu.connected(components[cmp].first(), it) }!!
            val minIn = components[cmp].minByOrNull { a[it] }!!
            var minEdge = Edge(minIn, minOut, a[minIn] + a[minOut])
            for (vertex in components[cmp]) {
                offers[vertex].removeAll { e -> dsu.connected(e.u, e.v) }
                for (offer in offers[vertex]) minEdge = minOf(minEdge, offer)
            }
            edges.add(minEdge)
        }
        for (edge in edges) {
            if (dsu.connected(edge.u, edge.v)) continue
            val root = processed(edge)
            dsu.unite(root.u, root.v)
            ans += root.cost
            if (dsu.size[root.u] < dsu.size[root.v]) {
                components[root.v].addAll(components[root.u])
                components[root.u].clear()
            } else {
                components[root.u].addAll(components[root.v])
                components[root.v].clear()
            }
        }
    }
    println(ans)
}