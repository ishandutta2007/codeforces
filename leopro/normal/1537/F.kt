fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val init = readLine()!!.split(' ').map { it.toInt() }
        val aim = readLine()!!.split(' ').map { it.toInt() }

        val graph = List(n) { mutableListOf<Int>() }
        repeat(m) {
            val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1 }
            graph[u].add(v)
            graph[v].add(u)
        }
        if ((init.sum() - aim.sum()) % 2 != 0) return@repeat println("NO")
        val color = IntArray(graph.size) { -1 }
        fun isBipartite(cur: Int, col: Int): Boolean {
            if (color[cur] == col) return true
            if (color[cur] == col xor 1) return false
            color[cur] = col
            for (next in graph[cur]) if (!isBipartite(next, col xor 1)) return false
            return true
        }
        if (!isBipartite(0, 0)) return@repeat println("YES")
        var leftAdd = 0L
        var rightAdd = 0L
        for (i in 0 until n) {
            if (color[i] == 0) {
                leftAdd += aim[i] - init[i]
            } else {
                rightAdd += aim[i] - init[i]
            }
        }
        println(if (leftAdd == rightAdd) "YES" else "NO")
    }
}