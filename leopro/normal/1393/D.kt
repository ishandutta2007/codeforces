import java.lang.Integer.min
import java.util.*

fun valid(i: Int, j: Int, n: Int, m: Int): Boolean = i in 0 until n && j in 0 until m

fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val rows = Array(n) { "" }
    for (i in rows.indices) {
        rows[i] = readLine()!!
    }

    val maxMainLine = Array(n) { IntArray(m) { 1 } }
    for (i in (n - 1) downTo 0) {
        for (j in (m - 1) downTo 0) {
            if (valid(i + 1, j + 1, n, m) && rows[i + 1][j + 1] == rows[i][j]) {
                maxMainLine[i][j] = maxMainLine[i + 1][j + 1] + 1
            }
        }
    }

    val incr = ArrayDeque<Int>()
    val ans = Array(n) { IntArray(m) }
    for (sum in 0..n + m - 2) {
        for (i in 0 until n) {
            val j = sum - i
            if (j !in 0 until m) continue
            if (!valid(i - 1, j + 1, n, m) || rows[i - 1][j + 1] != rows[i][j]) incr.clear()
            if (incr.isEmpty()) incr.addLast(i)
            for (i2 in incr.peekLast() + 1..n) {
                val j2 = sum - i2
                if (!valid(i2, j2, n, m) || rows[i2][j2] != rows[i][j]) {
                    ans[i][j] = i2 - i
                    break
                }
                val iMin = incr.peekFirst()
                val jMin = sum - iMin
                if (i + min(maxMainLine[i2][j2], maxMainLine[iMin][jMin]) > i2) {
                    while (!incr.isEmpty() && maxMainLine[incr.peekLast()][sum - incr.peekLast()] > maxMainLine[i2][j2]) incr.pollLast()
                    incr.addLast(i2)
                } else {
                    ans[i][j] = min(i2 - i, maxMainLine[iMin][jMin])
                    break
                }
            }
            if (incr.peekFirst() == i) incr.pollFirst()
        }
    }
    var sum = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (valid(i + 1, j, n, m) && rows[i][j] == rows[i + 1][j]) {
                sum += min(ans[i][j], ans[i + 1][j] + 1)
            } else {
                sum++
            }
        }
    }
    println(sum)
}