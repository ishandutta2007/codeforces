import kotlin.math.min

fun solveA() {
    var (n, k, x, y) = readLine()!!.split(" ").map { x -> x.toInt() }
    var a = readLine()!!.split(" ").map { x -> x.toInt() }.sortedDescending()
    var sum: Long = 0
    var tmp: Long = 0
    for (t in a)  {
        sum += t
        if (t > k)
            tmp += x
    }
    var res: Long = 0
    var i = 0
    var mx = k.toLong() * n.toLong()
    while (sum > mx && i < n && a[i] > k) {
        sum -= a[i]
        i++
        res += x
    }
    if (i < n && a[i] > k)
        res += y
    res = min(res, tmp)
    println(res)
}

fun main() {
    val tt = readLine()!!.toInt()
    for (ti in 0 until tt) {
        solveA()
    }
}