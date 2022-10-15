fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = listOf(0) + readLine()!!.split(' ').map { it.toInt() }
        val dp = List(n + 1) { IntArray(n + 1) { Int.MIN_VALUE } }
        dp[0][0] = 0
        for (i in 1..n) {
            for (j in 1..n) {
                dp[i][j] = maxOf(dp[i - 1][j - 1], dp[i - 1][j] - (a[i - 1] == j).toInt()) + (a[i] == j).toInt()
            }
        }
        if (dp[n].none { it >= k }) return@repeat println(-1)
        println(n - dp[n].indices.findLast { dp[n][it] >= k }!!)
    }
}

fun Boolean.toInt() = if (this) 1 else 0