import java.util.*

fun check(n: Int, x: Int, y: Int, p: Int): Int {
        var p = p
        val l = p - 1 + Integer.min(x - 1, p - x)
        p++
        val r = n - p + Integer.min(n - y, y - p)
        return Integer.max(l, r)
    }

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T > 0) {
            val n = scanner.nextInt()
            var x = scanner.nextInt()
            var y = scanner.nextInt()
            if (x > y) {
                val tx = x
                x = y
                y = tx
            }
            var L = x
            val R = y - 1
            var ans = check(n, x, y, L)
            while (L <= R) {
                ans = Integer.min(ans, check(n, x, y, L))
                L++
            }
            println(ans)
            T--
        }
    }