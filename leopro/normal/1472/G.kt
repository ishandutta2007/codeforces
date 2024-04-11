fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val roads = Array(n) { mutableListOf<Int>() }
        repeat(m) {
            val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1 }
            roads[u].add(v)
        }
        val d = IntArray(n) { Int.MAX_VALUE }
        d[0] = 0
        val bfs = ArrayDeque<Int>()
        bfs.add(0)
        while (bfs.isNotEmpty()) {
            val cur = bfs.removeFirst()
            for (next in roads[cur]) {
                if (d[next] > d[cur] + 1) {
                    d[next] = d[cur] + 1
                    bfs.addLast(next)
                }
            }
        }
        val ans = (0 until n).map { city -> d[roads[city].filter { d[it] < d[city] }.minByOrNull { d[it] } ?: city] }
            .toIntArray()
        for (city in (0 until n).sortedByDescending { d[it] }.toIntArray()) {
            for (next in roads[city]) {
                if (d[next] == d[city] + 1) {
                    ans[city] = minOf(ans[city], ans[next])
                }
            }
        }
        println(ans.joinToString(" "))
    }
}