import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T: Int
        T = scanner.nextInt()
        while (T-- > 0) {
            var n: Int
            n = scanner.nextInt()
            val a = LongArray(n + 1)
            for (i in 1..n) {
                a[i] = scanner.nextLong()
            }
            var ans: Long = 0
            for (i in 1..n) {
                var cnt: Long = 0
                for (j in 1..n) {
                    if (a[j] >= a[i]) cnt += a[i]
                }
                if (ans < cnt) ans = cnt
            }
            println(ans)
        }
    }