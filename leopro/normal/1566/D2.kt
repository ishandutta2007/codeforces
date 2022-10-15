fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }
        val lvl = List(n) { IntArray(m) }
        val s = a.sorted()
        var idx = 0
        for (i in 0 until n) {
            for (j in 0 until m) {
                lvl[i][j] = s[idx++]
            }
        }
        val closed = lvl.map { it.map { false }.toBooleanArray() }
        val lastFree = IntArray(n) { lvl[it].last() }
        var ans = 0
        for (x in a) {
            val row = (0 until n).find { lastFree[it] >= x }!!
            var place = -1
            for (j in lvl[row].indices) {
                if (lvl[row][j] > x) break
                if (!closed[row][j] && lvl[row][j] == x) place = j
            }
            for (j in 0 until place) {
                if (closed[row][j]) ans++
            }
            closed[row][place] = true
            if (lastFree[row] <= x) {
                lastFree[row] = -1
                for (j in 0 until place) {
                    if (!closed[row][j]) lastFree[row] = lvl[row][j]
                }
            }
        }
        println(ans)
    }
}

infix fun Int.ceil(other: Int): Int = (this + other - 1) / other