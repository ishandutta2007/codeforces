import kotlin.system.exitProcess

class Edge(val a: Int, val b: Int, val weight: Int, val i: Int = 0) {
    fun get(cur: Int) = a + b - cur
}

fun Boolean.toInt() = if (this) 1 else 0

class DSU(n: Int) {
    private val parent = IntArray(n) { it }
    private val size = IntArray(n) { 1 }
    var components = n
    private fun component(x: Int): Int = if (x == parent[x]) x else component(parent[x])
    fun connected(x: Int, y: Int) = component(x) == component(y)
    fun connect(x: Int, y: Int) {
        val a = component(x)
        val b = component(y)
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

fun main() {
    val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
    val links = Array(n) { MutableList(0) { Edge(0, 0, 0) } }
    val edges = Array(m) { Edge(0, 0, 0) }
    for (e in 0 until m) {
        val (a, b, w) = readLine()!!.split(' ').mapIndexed { index, it -> it.toInt() - (index < 2).toInt() }
        edges[e] = Edge(a, b, w, e + 1)
        links[a].add(edges[e])
        links[b].add(edges[e])
    }
    val component = IntArray(n) { -1 }

    fun dfsWithoutCapital(cur: Int, c: Int) {
        if (component[cur] == c) return
        component[cur] = c
        for (next in links[cur]) if (next.get(cur) != 0) dfsWithoutCapital(next.get(cur), c)
    }

    var c = 0
    for (city in 1 until n) if (component[city] == -1) dfsWithoutCapital(city, c++)

    val dsu = DSU(n)
    val tree = Array(n) { MutableList(0) { Edge(0, 0, 0) } }
    for (step in 0..1) {
        for (e in edges.sortedBy { it.weight }) {
            if ((component[e.a] == component[e.b] || step == 1) && !dsu.connected(e.a, e.b)) {
                dsu.connect(e.a, e.b)
                tree[e.a].add(e)
                tree[e.b].add(e)
            }
        }
    }
    if (c > k || dsu.components > 1) {
        println(-1)
        exitProcess(0)
    }

    for (step in 1..k - c) {
        val maxEdge = Array(n) { Edge(0, 0, 0) }
        fun setMaxEdge(cur: Int, prev: Int, max: Edge) {
            maxEdge[cur] = max
            for (next in tree[cur]) {
                if (next.get(cur) == prev) continue
                setMaxEdge(next.get(cur), cur, maxOf(max, next, Comparator { a, b -> a.weight - b.weight }))
            }
        }
        for (link in tree[0]) setMaxEdge(link.get(0), 0, Edge(0, 0, 0))

        val newRoad = links[0].filter { maxEdge[it.get(0)].weight != 0 }
            .maxBy { maxEdge[it.get(0)].weight - it.weight }!!
        tree[0].add(newRoad)
        tree[newRoad.get(0)].add(newRoad)
        tree[maxEdge[newRoad.get(0)].a].remove(maxEdge[newRoad.get(0)])
        tree[maxEdge[newRoad.get(0)].b].remove(maxEdge[newRoad.get(0)])
    }
    println(n - 1)
    for (city in 0 until n) {
        for (e in tree[city]) {
            if (e.get(city) < city) print("${e.i} ")
        }
    }
}