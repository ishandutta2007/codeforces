fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        if (a.find { it % 2 == 1 } != null) return@repeat println(a.count { it % 2 == 0 })
        val sum = a.fold(0L) { a, b -> a + b }
        val ans = a.minOf { trailingZeroes(it.toLong()) } + n - 1
        println(ans)
    }
}

fun trailingZeroes(x: Long): Int {
    var t = 0
    while ((1L shl t) and x == 0L) t++
    return t
}