fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, s) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val p = IntArray(n + 1)
        for (i in a.indices) p[i + 1] = p[i] + a[i]
        val minWhere = IntArray(n+1) { -1 }
        for (i in 0..n) {
            if (minWhere[p[i]] == -1) minWhere[p[i]] = i
        }
        if (s < 0 || s > p[n]) return@repeat println(-1)
        var ans = 0
        for (i in 0..n) {
            if (p[i] >= s && minWhere[p[i] - s] != -1) ans = maxOf(ans, i - minWhere[p[i]-s])
        }
        println(n-ans)
    }
}