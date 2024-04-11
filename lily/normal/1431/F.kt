import java.util.*

    fun work(n: Int, a: ArrayList<Long>, K: Int, X: Int, m: Long): Boolean {
        val q = PriorityQueue<Long>()
        var sum: Long = 0
        var cur: Long = 0
        var cnt: Long = 0
        for (i in a) {
            q.add(-i)
            sum += i
            if (sum > m) {
                sum -= -q.poll()
                cnt++
            } else {
                cur++
            }
            if (cur == X.toLong()) {
                cur = 0
                sum = cur
                q.clear()
            }
        }
        return cnt <= K
    }

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T: Int
        T = 1
        while (T-- > 0) {
            var n: Int
            var K: Int
            var X: Int
            n = scanner.nextInt()
            K = scanner.nextInt()
            X = scanner.nextInt()
            val a = ArrayList<Long>()
            for (i in 1..n) a.add(scanner.nextLong())
            if (K >= n) {
                println(0)
                continue
            }
            var l: Long = 0
            var r = 100000000000L
            while (l < r) {
                val m = (l + r) / 2
                if (work(n, a, K, X, m)) r = m else l = m + 1
            }
            println(l)
        }
    }