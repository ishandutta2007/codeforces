fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val graph = Array<MutableList<Int>>(n) { mutableListOf() }
        for (edge in 1 until n) {
            val (x, y) = readLine()!!.split(' ').map { it.toInt() - 1 }
            graph[x].add(y)
            graph[y].add(x)
        }
        val root = graph.indices.find { graph[it].size == 1 }!!
        val size = IntArray(n) { 1 }
        fun dfs(cur: Int, prev: Int): Int {
            for (next in graph[cur]) if (prev != next) size[cur] += dfs(next, cur)
            return size[cur]
        }
        dfs(root, root)
        fun findCentroid(cur: Int, prev: Int): Int {
            val maxChild = graph[cur].filter { it != prev }.maxBy { size[it] }!!
            if (size[maxChild] * 2 >= n) return findCentroid(maxChild, cur)
            return cur
        }
        val centroid = findCentroid(root, root)
        if (size[centroid] * 2 > n) {
            println("${root + 1} ${graph[root][0] + 1}\n${root + 1} ${graph[root][0] + 1}")
        } else {
            println("${root + 1} ${graph[root][0] + 1}\n${root + 1} ${centroid + 1}")
        }
    }
}