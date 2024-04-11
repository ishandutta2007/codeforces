import java.lang.Long.max
import java.lang.Long.min
import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        val n: Int
        val m: Int
        val K: Int
        n = scanner.nextInt()
        m = scanner.nextInt()
        K = scanner.nextInt()
        val a = LongArray(n)
        val b = LongArray(m)
        val c = Array(n) { LongArray(m) }
        val d = LongArray(n + m + 1)
        val e = LongArray(n + m + 1)
        val f = LongArray(n + m + 1)
        var dc = 0
        val S: MutableSet<Long> = TreeSet()
        val map: MutableMap<Long, Int> = HashMap()
        for (i in 0 until n) {
            a[i] = scanner.nextLong()
            S.add(a[i])
        }
        for (i in 0 until m) {
            b[i] = scanner.nextLong()
            S.add(b[i])
        }
        for (v in S) {
            d[++dc] = v
            map[v] = dc
        }
        for (i in 0 until n) {
            for (j in 0 until m) {
                c[i][j] = scanner.nextLong()
                val id = map[max(a[i], b[j])]!!
                e[id] = max(e[id], c[i][j])
            }
        }
        var ans = 0x3f3f3f3f3f3f3f3fL
        for (t in 1..dc) {
            e[t] += K.toLong()
            for (i in 1..dc) {
                f[i] = max(e[i], f[i - 1])
            }
            var cur: Long = 0
            var r: Long = 0
            var id = 1
            while (id < dc) {
                while (id < dc && cur >= d[id + 1]) {
                    id++
                }
                if (id == dc) break
                val dif = d[id + 1] - cur
                val need = (dif + f[id] - 1) / f[id]
                r += need
                cur += need * f[id]
            }
            ans = min(ans, r)
            e[t] -= K.toLong()
        }
        println(ans)
    }