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
        T = scanner.nextInt()
        while (T-- > 0) {
            var n: Int
            n = scanner.nextInt()
            val a = ArrayList<Int>()
            val b = ArrayList<Int>()
            for (i in 1..n) a.add(scanner.nextInt())
            for (i in 1..n) b.add(scanner.nextInt())
            var L = 0
            var R = n - 1
            while (R - L > 7) {
                val ML = (L * 2 + R) / 3
                val MR = (L + R * 2) / 3
                if (work(n, a, b, ML) > work(n, a, b, MR)) R = MR else L = ML
            }
            var ans = 0
            var id = 0
            for (i in L..R) {
                val ret = work(n, a, b, i)
                ans = Integer.max(ans, ret)
                if (ans == ret) id = i
            }
            for (i in 0 until n) {
                System.out.printf("%d%c", (i + id) % n + 1, if (i == n - 1) '\n' else ' ')
            }
        }
    }