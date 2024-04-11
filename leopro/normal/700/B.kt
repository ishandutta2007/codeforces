fun main() {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    val universities = readLine()!!.split(' ').map { it.toInt() - 1 }
    val edges = List(n) { mutableListOf<Int>() }
    repeat(n - 1) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() - 1 }
        edges[x].add(y)
        edges[y].add(x)
    }
    val count = IntArray(n)
    val depth = IntArray(n)
    for (u in universities) count[u]++
    fun dfs(cur: Int, prev: Int): Int {
        for (next in edges[cur]) {
            if (next == prev) continue
            depth[next] = depth[cur] + 1
            count[cur] += dfs(next, cur)
        }
        return count[cur]
    }
    dfs(0, 0)
    val center = count.indices.filter { count[it] >= k }.minWithOrNull(compareBy<Int> { count[it] }.thenBy { -depth[it] })
    val dist = IntArray(n) { v -> if (v == center) 0 else Int.MAX_VALUE }
    val dfs = mutableListOf(center)
    while (dfs.isNotEmpty()) {
        val cur = dfs.removeLast()!!
        for (next in edges[cur]) {
            if (dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1
                dfs.add(next)
            }
        }
    }
    println(universities.sumOf { dist[it].toLong() })
}