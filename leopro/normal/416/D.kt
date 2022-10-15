fun main() {
    val n = readLine()!!.toInt()
    if (n <= 2) return println(1)
    val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    if (a.find { it != -1 } == null) return println(1)
    val prev = IntArray(n) { -1 }
    val next = IntArray(n) { n }
    run {
        var last = -1
        for (i in a.indices) {
            if (a[i] != -1) last = i
            prev[i] = last
        }
    }
    run {
        var front = n
        for (i in a.indices.reversed()) {
            if (a[i] != -1) front = i
            next[i] = front
        }
    }

    fun diff(i: Int, j: Int): Int {
        if (i == -1 || j == n || a[i] == -1 || a[j] == -1 || i == j) return 0
        return (a[j] - a[i]) / (j - i)
    }

    val possibleValues = List(n) { mutableListOf<Long>() }
    for (i in a.indices) {
        if (a[i] != -1) {
            possibleValues[i].add(a[i].toLong())
        } else {
            val l = prev[i]
            val r = next[i]
            if (l >= 0) possibleValues[i].add(a.getOrElse(l) { 0 }.toLong())
            if (r < n) possibleValues[i].add(a.getOrElse(r) { 0 }.toLong())
            if (l >= 0 && r < n) possibleValues[i].add(a.getOrElse(l) { 0 } + diff(l, r) * 1L * (i - l))
            if (prev.getOrElse(l - 1) { -1 }!=-1) {
                possibleValues[i].add(a.getOrElse(l) { 0 } + diff(prev.getOrElse(l - 1) { -1 }, l) * 1L * (i - l))
            }
            if (next.getOrElse(r + 1) { n } != n) {
                possibleValues[i].add(a.getOrElse(r) { 0 } - diff(r, next.getOrElse(r + 1) { n }) * 1L * (r - i))
            }
        }
        possibleValues[i].removeIf { it <= 0 }
    }
    val result = List(n) { possibleValues[it].toLongArray() }
    val dp = List(n - 1) { i -> IntArray(result[i].size * result[i + 1].size) { n } }
    val min = IntArray(n - 1) { n }
    dp[0].fill(1)
    min[0] = 1
    for (i in 2 until n) {
        val size = result[i].size
        val prev = result[i - 1].size
        for ((i1, x1) in result[i - 2].withIndex()) {
            for ((i2, x2) in result[i - 1].withIndex()) {
                for ((i3, x3) in result[i].withIndex()) {
                    if (x3 - x2 == x2 - x1) {
                        dp[i - 1][i2 * size + i3] = minOf(
                            dp[i - 1][i2 * size + i3],
                            dp[i - 2][i1 * prev + i2]
                        )
                    }
                    if (i >= 3) {
                        dp[i - 1][i2 * size + i3] = minOf(
                            dp[i - 1][i2 * size + i3],
                            min[i - 3] + 1
                        )
                    }
                    dp[i - 1][i2 * size + i3] = minOf(
                        dp[i - 1][i2 * size + i3],
                        dp[i - 2][i1 * prev + i2] + 1
                    )
                }
            }
        }
        min[i - 1] = dp[i - 1].minOf { it }
    }
    println(dp[n - 2].minOf { it })
}