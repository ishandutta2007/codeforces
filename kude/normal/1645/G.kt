fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!.reversed().map { it - 'a' }
    val t = readLine()!!.reversed().map { it - 'a' }
    val u = IntArray(n + 1)
    var v = 0
    for (i in 0 until n) {
        v += s[i] + t[i]
        u[i] = v % 26
        v /= 26
    }
    u[n] = v
    v = 0
    for (i in n downTo 0) {
        v *= 26
        v += u[i]
        u[i] = v / 2
        v %= 2
    }
    require(v == 0)
    val ans = CharArray(n) { 'a' + u[n - 1 - it] }
    println(ans.joinToString(""))
}