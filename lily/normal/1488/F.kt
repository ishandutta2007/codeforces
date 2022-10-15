import java.util.*

var comp = qc()
var c = IntArray(200002)
var t = LongArray(200002)
var v = LongArray(200002)
var ans = LongArray(200002)
var n = 0
var Q = 0
var q = arrayOfNulls<qr>(200002)
fun upd(x: Int, y: Long) {
    var x = x
    while (x <= n) {
        t[x] += y
        x += x and -x
    }
}

fun qry(x: Int): Long {
    var x = x
    if (x == 0) return 0
    var ans: Long = 0
    while (x > 0) {
        ans += t[x]
        x -= x and -x
    }
    return ans
}

fun sset(x: Int, y: Long) {
    upd(x, y - v[x])
    v[x] = y
}

fun main(args: Array<String>) {
    var T = 1
    while (T > 0) {
        n = readLine()!!.toInt()
        val cc = readLine()!!.split(' ').map { it.toInt() }
        for (i in 1..n) {
            c[i] = cc[i - 1]
        }
        Q = readLine()!!.toInt()
        for (i in 1..Q) {
            q[i] = qr()
            val (l, r) = readLine()!!.split(' ').map { it.toInt() }
            q[i]!!.l = l
            q[i]!!.r = r
            q[i]!!.id = i
        }
        Arrays.sort(q, 1, Q + 1, comp)
        for (i in 1..n) {
            v[i] = 0
            t[i] = 0
        }
        val p = IntArray(n + 2)
        var top = 0
        var cur = 1
        for (i in 1..n) {
            while (top > 0 && c[p[top]] <= c[i]) {
                sset(top, 0)
                top--
            }
            top++
            p[top] = i
            sset(top, (p[top] - p[top - 1]).toLong() * c[i].toLong())
            while (cur <= Q && q[cur]!!.r == i) {
                var l = 1
                var r = top
                while (l < r) {
                    val mid = (l + r) / 2
                    if (p[mid] >= q[cur]!!.l) {
                        r = mid
                    } else l = mid + 1
                }
                ans[q[cur]!!.id] = qry(top) - qry(l - 1) - c[p[l]].toLong() * (q[cur]!!.l.toLong() - 1 - p[l - 1])
                cur++
            }
        }
        println((1..Q).joinToString(" ") { ans[it].toString() })
//        for (i in 1..Q) {
//            System.out.printf("%d%c", ans[i], if (i == Q) '\n' else ' ')
//        }
        T--
    }
}

class qr {
    var l = 0
    var r = 0
    var id = 0
}

class qc : Comparator<Any?> {
    override fun compare(o1: Any?, o2: Any?): Int {
        return Integer.compare((o1 as qr?)!!.r, (o2 as qr?)!!.r)
    }
}