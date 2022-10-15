fun main() {
    val n = readLine()!!.toInt()
    val dp = Array(n + 1) { IntArray(20_001) { -20_001 } }
    dp[0][0] = 0
    for (i in 0 until n) {
        val (a, b) = readLine()!!.split(' ').map { it.toInt() * 2 }
        for (j in i + 1 downTo 0) {
            for (capacity in dp[j].lastIndex - a downTo -a step 2) {
                if (capacity >= 0 && j > 0)
                    dp[j][capacity + a] = maxOf(dp[j][capacity + a] + b / 2, dp[j - 1][capacity] + b)
                else
                    dp[j][capacity + a] += b / 2
            }
        }
    }
    val ans = (1..n).map { dp[it].foldIndexed(0) { index, acc, i -> maxOf(acc, minOf(index, i)) } / 2.0 }
    println(ans.joinToString(" "))
}