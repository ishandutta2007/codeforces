fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        val dp = IntArray(n) { n }
        dp[0] = 0
        val furthest = IntArray(n)
        for (i in 1 until n) {
            var cnt = 0
            for (j in i - 1 downTo 0) {
                if (j + a[j] < i) continue
                val new = dp[j] + cnt + (furthest[j] >= i).toInt()
                if (new < dp[i]) {
                    dp[i] = new
                    furthest[i] = if (furthest[j] >= i) furthest[j] else j + a[j]
                } else if (new == dp[i]) {
                    furthest[i] = minOf(furthest[i], if (furthest[j] >= i) furthest[j] else j + a[j])
                }
                cnt++
            }
        }
        println(dp[n - 1])
    }
}

fun Boolean.toInt() = if (this) 1 else 0