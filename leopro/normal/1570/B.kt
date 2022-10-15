fun main() {
    val a1 = readLine()!!.toInt()
    val a2 = readLine()!!.toInt()
    val k1 = readLine()!!.toInt()
    val k2 = readLine()!!.toInt()
    val n = readLine()!!.toInt()
    if (k1 < k2) {
        solve(a1, a2, k1, k2, n)
    } else {
        solve(a2, a1, k2, k1, n)
    }
}

fun solve(a1: Int, a2: Int, k1: Int, k2: Int, n: Int) {
    print("${(n - a1 * (k1 - 1) - a2 * (k2 - 1)).coerceAtLeast(0)} ")
    if (n <= k1 * a1) {
        println(n / k1)
    } else {
        println(a1 + (n - k1 * a1) / k2)
    }
}