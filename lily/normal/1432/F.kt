import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        val n: Int
        val m: Int
        val d: Int
        n = scanner.nextInt()
        m = scanner.nextInt()
        d = scanner.nextInt()
        val a = IntArray(n + 2)
        val c = IntArray(m + 1)
        var cur = 0
        for (i in 1..m) {
            c[i] = scanner.nextInt()
            cur += d
            cur += c[i] - 1
        }
        cur += d
        if (cur <= n) println("NO") else {
            val csum = IntArray(m + 2)
            for (i in m downTo 1) {
                csum[i] = csum[i + 1] + c[i]
            }
            cur = 0
            for (i in 1..m) {
                var nxt = cur + d + c[i] - 1
                val needed = n - csum[i + 1]
                if (nxt > needed) {
                    nxt = needed
                }
                for (j in c[i] - 1 downTo 0) {
                    a[nxt - j] = i
                }
                cur = nxt
            }
            println("YES")
            for (i in 1..n) {
                System.out.printf("%d%c", a[i], if (i == n) '\n' else ' ')
            }
        }
    }