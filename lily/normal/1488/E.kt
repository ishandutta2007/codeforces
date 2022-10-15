import java.util.*

    var t = IntArray(250002)
    var n = 0
    fun qry(x: Int): Int {
        var x = x
        var ret = 0
        while (x <= n) {
            ret = Integer.max(ret, t[x])
            x += x and -x
        }
        return ret
    }

    fun upd(x: Int, y: Int) {
        var x = x
        while (x > 0) {
            t[x] = Integer.max(t[x], y)
            x -= x and -x
        }
    }

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T > 0) {
            n = scanner.nextInt()
            val a = IntArray(n + 1)
            for (i in 0..n + 1) {
                t[i] = 0
            }
            val m = HashMap<Int, Int>()
            val ff = HashMap<Int, Int>()
            for (i in 1..n) {
                a[i] = scanner.nextInt()
                m[a[i]] = m.getOrDefault(a[i], 0) + 1
            }
            for (i in 1..n) {
                if (m[a[i]] == 1) {
                } else {
                    if (ff.getOrDefault(a[i], -1) == -1) {
                        ff[a[i]] = i
                    }
                }
            }
            for (i in 1..n) {
                val l = ff.getOrDefault(a[i], -1)
                if (l != -1 && l != i) {
                    val ret = qry(l + 1)
                    upd(l, ret + 2)
                }
                upd(i, 1)
            }
            println(qry(1))
            T--
        }
    }