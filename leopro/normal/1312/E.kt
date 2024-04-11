fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val dp = Array(n) { IntArray(n - it + 1) { -1 } }
    for (i in a.indices) dp[i][1] = a[i]
    for (len in 2..n) {
        for (i in a.indices) {
            if (len > n - i) continue
            for (d in 1 until len) {
                if (dp[i][d] == dp[i + d][len - d] && dp[i][d] != -1) dp[i][len] = dp[i][d] + 1
            }
        }
    }
    val minCount = IntArray(n + 1) { it }
    for (i in 1..n) {
        for (j in 0 until i) {
            if (dp[j][i - j] != -1) minCount[i] = minOf(minCount[i], minCount[j] + 1)
        }
    }
    println(minCount[n])
}