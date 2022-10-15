fun main() {
    val ans = mutableListOf<Int>()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val tmp = List(n) { mutableListOf<Int>() }
        repeat(n - 1) {
            val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1 }
            tmp[u].add(v)
            tmp[v].add(u)
        }
        val g = tmp.map { it.toIntArray() }
        val h = IntArray(n)
        val excluded = BooleanArray(n)

        var branches = 0

        fun dfs(cur: Int, prev: Int, limit: Int): Int {
            if (limit < 0) return -1
            var children = 0
            for (next in g[cur]) {
                if (next == prev) continue
                h[cur] = maxOf(h[cur], 1 + dfs(next, cur, limit - 1))
                if (!excluded[next]) children++
            }
            if (h[cur] == 1 && limit > 0) {
                branches += children - 1
                excluded[cur] = true
                return -1
            }
            return h[cur]
        }
        repeat(100) { dfs(0, 0, 0) }
        dfs(0, 0, Int.MAX_VALUE)

        fun exclude(cur: Int, prev: Int, e: Boolean, limit: Int) {
            if (limit < 0) return
            if (e) excluded[cur] = e
            var current = 0
            for (next in g[cur]) {
                if (next == prev) continue
                exclude(next, cur, e || excluded[cur], limit - 1)
                if (!excluded[cur] && !excluded[next]) current++
            }
            if (limit > 0) branches += current.coerceAtLeast(0)
        }
        repeat(100) { exclude(0, 0, false, 0) }
        exclude(0, 0, false, Int.MAX_VALUE)

        ans.add(1 + branches)
    }
    println(ans.joinToString("\n"))
}

infix fun Int.ceil(other: Int): Int = (this + other - 1) / other