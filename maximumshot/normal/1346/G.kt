import java.lang.Integer.max
import java.lang.Integer.min

val INF = 1000000000

var tree_gcd = ArrayList<Int>()

fun gcd(x: Int, y: Int): Int {
    if (x == 0)
        return y
    else
        return gcd(y % x, x)
}

fun build(xs: ArrayList<Int>, v: Int, tl: Int, tr: Int) {
    if (tl == tr) {
        if (tl > 0)
            tree_gcd[v] = xs[tl] - xs[tl - 1]
        else
            tree_gcd[v] = xs[tl]
    } else {
        var tm = (tl + tr) / 2
        build(xs, v * 2, tl, tm)
        build(xs, v * 2 + 1, tm + 1, tr)
        tree_gcd[v] = gcd(tree_gcd[v * 2], tree_gcd[v * 2 + 1])
    }
}

fun query(v: Int, tl: Int, tr: Int, l: Int, r: Int): Int {
    if (l <= tl && tr <= r)
        return tree_gcd[v]
    else {
        var tm = (tl + tr) / 2
        var res = 0
        if (l <= tm)
            res = gcd(res, query(v * 2, tl, tm, l, r))
        if (r > tm)
            res = gcd(res, query(v * 2 + 1, tm + 1, tr, l, r))
        return res
    }
}

fun solveA() {
    var (k, n) = readLine()!!.split(" ").map { x -> x.toInt() }
    var ps = ArrayList<Int>()

    var ps_tmp = readLine()!!.split(" ").map { x -> x.toInt() }

    for (t in ps_tmp) {
        ps.add(t)

    }

    ps_tmp = readLine()!!.split(" ").map { x -> x.toInt() }

    var xs = ArrayList<Int>()
    for (t in ps_tmp) {
        xs.add(t)
    }

    for (iter in 0 until 4 * n) {
        tree_gcd.add(0)
    }

    build(xs, 1, 0, n - 1)

    var mn = ArrayList<Int>()
    for (i in 0 until 1000005) {
        mn.add(INF)
    }

    for (p in ps) {
        var x = p
        while (x < mn.size) {
            mn[x] = min(mn[x], p)
            x += p
        }
    }

    for (p in ps) {
        var cur = xs[0]
        var last_gcd = -INF
        var total_gcd = 0
        var first = -INF
        while (cur <= xs[n - 1]) {
            var l = cur
            var r = cur + p

            var bl = -1
            var br = n - 1
            var bm = 0

            while (br - bl > 1) {
                bm = (bl + br) / 2
                if (xs[bm] > l)
                    br = bm
                else
                    bl = bm
            }

            var ql = br

            bl = 0
            br = n
            while (br - bl > 1) {
                bm = (bl + br) / 2
                if (xs[bm] < r)
                    bl = bm
                else
                    br = bm
            }

            var qr = bl

            if (0 <= ql && ql <= qr && qr < n && l < xs[ql] && xs[qr] < r) {
                if (last_gcd != -INF) {
                    total_gcd = gcd(total_gcd, xs[ql] - last_gcd)
                } else {
                    first = xs[ql]
                }
                last_gcd = xs[qr]
                if (ql + 1 <= qr) {
                    var tmp = query(1, 0, n - 1, ql + 1, qr) // gcd on [ql + 1, qr]
                    total_gcd = gcd(total_gcd, tmp)
                }
            }

            if (ql == n)
                break

            if (cur + p < xs[ql]) {
                var kk = (xs[ql] - cur) / p
                kk = max(kk, 1)
                cur += kk * p
            } else {
                cur += p
            }
        }

        if (total_gcd == 0) {
            println("YES")
            if (first == -INF)
                first = xs[0]
            println("${xs[0]} $p")
            println("${first} $p")
            return
        }

        if (mn[total_gcd] != INF) {
            println("YES")
            println("${xs[0]} $p")
            println("${first} ${mn[total_gcd]}")
            return
        }
    }

    println("NO")
}

fun main() {
//    val tt = readLine()!!.toInt()
    val tt = 1
    for (ti in 0 until tt) {
        solveA()
    }
}