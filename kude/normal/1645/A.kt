fun main() {
    val tt = readLine()!!.toInt()
    for (t in 0 until tt) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val v = if (a[0] == a[1]) a[0] else a[2]
        val ans = a.withIndex().find { it.value != v }!!.let { it.index }
        println(ans + 1)
    }
}