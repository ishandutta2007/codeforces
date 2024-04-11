fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val p = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val g = List(n + 1) { mutableListOf<Int>() }
        for (i in a.indices) {
            g[a[i]].add(p[i])
        }
        val mx = (1..n).maxByOrNull { g[it].size }!!
        val color = IntArray(n + 1)
        var ok = true
        fun dfs(cur: Int) {
            if (color[cur] == 2) return
            if (color[cur] == 1) {
                ok = false
                return
            }
            color[cur] = 1
            for (next in g[cur]) if (next != mx) dfs(next)
            color[cur] = 2
        }
        for (i in 1..n) if (i != mx) dfs(i)
        println(if (ok) "AC" else "WA")
    }
}