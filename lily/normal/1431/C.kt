import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T: Int
        T = scanner.nextInt()
        while (T-- > 0) {
            var n: Int
            var K: Int
            n = scanner.nextInt()
            K = scanner.nextInt()
            val a = IntArray(n + 1)
            for (i in 1..n) {
                a[i] = scanner.nextInt()
            }
            var ans = 0
            for (i in 1..n) {
                if (i * K > n) break
                val tt = i * K
                var cnt = 0
                var j = n - tt + 1
                var k = i
                while (k-- > 0) {
                    cnt += a[j]
                    j++
                }
                if (cnt > ans) ans = cnt
            }
            println(ans)
        }
    }