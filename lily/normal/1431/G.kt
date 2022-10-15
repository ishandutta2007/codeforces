import java.util.*

    fun work(n: Int, a: ArrayList<Int>, b: ArrayList<Int>, d: Int): Int {
        var ret = 0x3f3f3f3f
        for (i in 0 until n) {
            ret = Integer.min(ret, Math.abs(a[i] - b[(i + d) % n]))
        }
        return ret
    }

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T: Int
        T = 1
        while (T-- > 0) {
            var n: Int
            var K: Int
            n = scanner.nextInt()
            K = scanner.nextInt()
            val a = IntArray(n + 1)
            val s = IntArray(n + 1)
            for (i in 1..n) a[i] = scanner.nextInt()
            Arrays.sort(a, 1, n + 1)
            for (i in 1..n) {
                s[i] = s[i - 1] + a[i]
            }
            var ans = 0
            val dp = Array(n + 1) { IntArray(K + 1) }
            for (k in 0..K) {
                for (i in 0..n) {
                    ans = Integer.max(ans, dp[i][k])
                    if (i > 0) dp[i][k] = Integer.max(dp[i][k], dp[i - 1][k])
                    var j = 1
                    while (i + 2 * j <= n && j + k <= K) {
                        dp[i + 2 * j][j + k] = Integer.max(dp[i + 2 * j][j + k], dp[i][k] + s[i + 2 * j] - s[i + j] - s[i + j] + s[i])
                        j++
                    }
                }
            }
            println(ans)
        }
    }