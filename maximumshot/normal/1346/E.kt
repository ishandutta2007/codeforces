import kotlin.math.max
import kotlin.math.min

fun solveA() {
    var (n, m, k) = readLine()!!.split(" ").map { x -> x.toInt() }
    var a = ArrayList<Int>()
    val INF: Int = -1000000000
    for (i in 0 until n) {
        a.add(INF)
    }
    k--
    a[k] = 0
    var cur = 0
    for (iter in 0 until m) {
        var (x, y) = readLine()!!.split(" ").map { x -> x.toInt() }
        x--
        y--
        cur++
        a[x]--
        a[y]--
        var dx = a[x] + cur
        var dy = a[y] + cur
        a[x] = max(dx, dy + 1) - cur
        a[y] = max(dy, dx + 1) - cur
    }
    for (x in a) {
        var t = x + cur
        if (t < 0)
            t = -1
        else
            t = m - t
        print("$t ")
    }
    println()
}

fun main() {
//    val tt = readLine()!!.toInt()
    val tt = 1
    for (ti in 0 until tt) {
        solveA()
    }
}