import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, i, j) = readLine()!!.split(' ').map { it.toInt() }
        var ans = 0L
        fun check(i1: Int, j1: Int, i2: Int, j2: Int) {
            val cur = abs(i - i1).toLong() + abs(i1 - i2) + abs(i - i2) + abs(j - j1) + abs(j1 - j2) + abs(j - j2)
            if (cur > ans) ans = cur
        }

        fun ans(i1: Int, j1: Int, i2: Int, j2: Int): Boolean {
            val cur = abs(i - i1).toLong() + abs(i1 - i2) + abs(i - i2) + abs(j - j1) + abs(j1 - j2) + abs(j - j2)
            if (cur == ans) println("$i1 $j1 $i2 $j2")
            return cur == ans
        }
        check(1, 1, n, m)
        check(1, 1, 1, m)
        check(1, 1, n, 1)
        check(n, 1, n, m)
        check(n, 1, 1, m)
        check(1, m, n, m)
        check(1, m, n, 1)

        if (ans(1, 1, n, m)) return@repeat
        if (ans(1, 1, 1, m)) return@repeat
        if (ans(1, 1, n, 1)) return@repeat
        if (ans(n, 1, n, m)) return@repeat
        if (ans(n, 1, 1, m)) return@repeat
        if (ans(1, m, n, m)) return@repeat
        if (ans(1, m, n, 1)) return@repeat
    }
}