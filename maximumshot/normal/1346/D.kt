import kotlin.math.max
import kotlin.math.min

fun solveA() {
    var (n, m) = readLine()!!.split(" ").map { x -> x.toInt() }
    var a = ArrayList<Int>()
    for (i in 0 until n)
        a.add(0)
    var edge = ArrayList<Pair<Int, Int>>()
    var weights = ArrayList<Int>()
    for (iter in 0 until m) {
        var (u, v, w) = readLine()!!.split(" ").map { x -> x.toInt() }
        u--
        v--
        edge.add(Pair(u, v))
        weights.add(w)
        a[u] = max(a[u], w)
        a[v] = max(a[v], w)
    }
    for (iter in 0 until m) {
        var (u, v) = edge[iter]
        var w = weights[iter]
        if (w != min(a[u], a[v])) {
            println("NO")
            return
        }
    }
    println("YES")
    for (x in a)
        print("$x ")
    println()
}

fun main() {
    val tt = readLine()!!.toInt()
    for (ti in 0 until tt) {
        solveA()
    }
}