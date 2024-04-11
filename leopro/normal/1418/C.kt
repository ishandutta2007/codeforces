import java.lang.Integer.min

fun main() {
    for (test in 0 until readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readInts().toIntArray()

        val dp = Array(2) { IntArray(n + 1) { 1_000_000 } }
        dp[0][0] = 0
        for (i in 1..n) {
            for (j in 0..1) {
                for (len in 1..2) {
                    if (len > i) continue
                    dp[j][i] = min(dp[j][i], dp[1 - j][i - len] + (if (j == 1) sum(i - len, i, a) else 0))
                }
            }
        }
        println(min(dp[0].last(), dp[1].last()))
    }
}

fun sum(i: Int, j: Int, a: IntArray): Int {
    var s = 0
    for (k in i until j) s += a[k]
    return s
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readLongs() = readLine()!!.split(' ').map { it.toLong() }