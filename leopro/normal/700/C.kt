data class Edge(private val u: Int, private val v: Int, val w: Int, val index: Int, var bridge: Boolean = false) {
    fun get(cur: Int) = u + v - cur
    override operator fun equals(other: Any?) = other is Edge && index == other.index
}

fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val (s, t) = readLine()!!.split(' ').map { it.toInt() - 1 }
    val edges = List(n) { mutableListOf<Edge>() }
    repeat(m) {
        val (x, y, w) = readLine()!!.split(' ').map { it.toInt() }
        Edge(x - 1, y - 1, w, it + 1).let { e ->
            edges[x - 1].add(e)
            edges[y - 1].add(e)
        }
    }
    val visited = BooleanArray(n)
    fun dfs(cur: Int, parent: Edge?, forbidden: Edge? = null): MutableList<Edge?> {
        if (cur == t) return mutableListOf(parent)
        if (visited[cur]) return mutableListOf()
        visited[cur] = true
        for (next in edges[cur]) {
            if (next == forbidden) continue
            val way = dfs(next.get(cur), next, forbidden)
            if (way.isNotEmpty()) return way.apply { add(parent) }
        }
        return mutableListOf()
    }

    val candidates = dfs(s, null).filterNotNull()
    var ans = if (candidates.isEmpty()) 0 else null
    var toBeClosed = mutableListOf<Edge>()
    for (candidate in candidates) {
        visited.fill(false)
        val depth = IntArray(n)
        edges.forEach { it.forEach { it.bridge = false } }
        val over = IntArray(n)
        fun findBridges(cur: Int, parent: Edge?) {
            if (visited[cur]) return
            visited[cur] = true
            for (next in edges[cur]) {
                if (next == candidate || next == parent) continue
                if (!visited[next.get(cur)]) {
                    depth[next.get(cur)] = depth[cur] + 1
                    findBridges(next.get(cur), next)
                    over[cur] += over[next.get(cur)]
                } else if (depth[next.get(cur)] < depth[cur]){
                    over[cur]++
                    over[next.get(cur)]--
                }
            }
            if (over[cur] == 0 && parent != null) parent.bridge = true
        }
        findBridges(s, null)
        visited.fill(false)
        val way = dfs(s, null, candidate).filterNotNull()
        val cur = if (way.isEmpty()) candidate.w else way.filter { it.bridge }.minOfOrNull { it.w }?.plus(candidate.w)
        if (cur != null && (ans == null || ans > cur)) {
            ans = cur
            toBeClosed = mutableListOf(candidate)
            if (way.isNotEmpty()) toBeClosed.add(way.filter { it.bridge }.minByOrNull { it.w }!!)
        }
    }
    println(ans ?: -1)
    if (ans != null) {
        println(toBeClosed.size)
        println(toBeClosed.joinToString(" ") { it.index.toString() })
    }
}