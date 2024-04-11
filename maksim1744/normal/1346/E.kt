/*
    author:  Maksim1744
    created: 26.10.2020 12:41:38
*/

import kotlin.math.*;

const val INF: Int = 1_000_000_000

fun main() {
    var (n, m, k) = readLine()!!.split(" ").map{ it.toInt() }
    --k
    var a = IntArray(n) { INF }
    a[k] = 0
    for (i in 0 until m) {
        var (x, y) = readLine()!!.split(" ").map{ it.toInt() }
        --x
        --y
        var ax = a[x]
        var ay = a[y]
        a[x] = min(ay, ax + 1)
        a[y] = min(ax, ay + 1)
    }
    for (i in 0 until n) {
        if (a[i] == INF) a[i] = -1
    }
    println(a.joinToString(" "));
}