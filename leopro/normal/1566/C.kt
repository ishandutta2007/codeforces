fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val rows = List(2) { readLine()!!.toCharArray() }
        val prev = List(2) { IntArray(n) { -1 } }
        for (i in 0 until n) {
            if (rows[0][i] == '0' || rows[1][i] == '0') prev[0][i] = i else if (i != 0) prev[0][i] = prev[0][i - 1]
            if (rows[0][i] == '1' || rows[1][i] == '1') prev[1][i] = i else if (i != 0) prev[1][i] = prev[1][i - 1]
        }
        val dp = IntArray(n + 1)
        for (i in 0 until n) {
            dp[i + 1] = dp[i]
            if (prev[0][i] != -1) {
                dp[i + 1] = maxOf(dp[i + 1], dp[prev[0][i]] + 1)
            }
            if (prev[1][i] != -1 && prev[0][i] != -1) {
                dp[i + 1] = maxOf(dp[i + 1], dp[minOf(prev[1][i], prev[0][i])] + 2)
            }
        }
        println(dp[n])
    }
}

infix fun Int.ceil(other: Int): Int = (this + other - 1) / other