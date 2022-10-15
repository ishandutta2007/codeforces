fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tree = Array(n) { mutableListOf<Int>() }
        for (i in 1 until n) {
            val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1 }
            tree[u].add(v)
            tree[v].add(u)
        }
        val depth = IntArray(n)
        fun dfs1(cur: Int, prev: Int = -1) {
            for (next in tree[cur]) {
                if (next == prev) continue
                depth[next] = depth[cur] + 1
                dfs1(next, cur)
            }
        }
        dfs1(0)
        var ans = 0
        fun dfs2(cur: Int, prev: Int = -1, root: Boolean = true): Int {
            val minDepth = tree[cur].filter { it != prev }.map { dfs2(it, cur, false) }.sortedDescending()
            if (minDepth.isEmpty()) return depth[cur]
            if (!root || (minDepth.size > 1 && minDepth[0] == minDepth[1])) {
                ans = maxOf(ans, minDepth[0] - depth[cur] + 1)
            } else {
                ans = maxOf(ans, minDepth[0] - depth[cur])
            }
            return minDepth.last()
        }
        dfs2(0)
        println(ans)
    }
}