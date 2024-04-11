import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val p = readLine()!!.split(' ').map { it.toInt() - 1 }.toIntArray()
        val cycles = mutableListOf<MutableList<Int>>()
        val cycle = IntArray(n) { -1 }
        var cyclesCount = 0
        for (i in p.indices) {
            if (cycle[i] >= 0) continue
            var j = i
            cycles.add(mutableListOf())
            while (cycle[j] == -1) {
                cycle[j] = cyclesCount
                cycles.last().add(j)
                j = p[j]
            }
            cyclesCount++
        }

        val used = BooleanArray(n) { false }
        val visited = BooleanArray(cyclesCount) { false }
        val q = mutableListOf<Int>()
        fun go(x: Int) {
            if (used[x]) return
            visited[cycle[x]] = true
            used[x] = true
            q.add(x)
            val next = p[x]
            if (next > 0 && cycle[x] != cycle[next - 1] && !visited[cycle[next - 1]]) go(next - 1)
            if (next + 1 < n && cycle[x] != cycle[next + 1] && !visited[cycle[next + 1]]) go(next + 1)
            go(next)
        }
        go(0)
        var sum = 0
        q.reverse()
        for (i in 0 until n - 1) sum += abs(q[i] - p[q[i + 1]])
        sum += abs(q[n - 1] - p[q[0]])
//        println(sum)
        println(q.map { it + 1 }.joinToString(" "))
    }
}