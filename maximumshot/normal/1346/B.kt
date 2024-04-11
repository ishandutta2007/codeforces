import kotlin.math.min

fun solveA() {
    var (n, k1, k2) = readLine()!!.split(" ").map { x -> x.toInt() }
    var s = readLine()!!
    var last = 0
    var res = 0
    for (i in 0 until n) {
        if (s[i] == '0') {
            last = 0
            continue
        }
        var x = min(k1, k2 - last)
        res += x
        last = x
    }
    println(res)
}

fun main() {
    val tt = readLine()!!.toInt()
    for (ti in 0 until tt) {
        solveA()
    }
}