fun main() {
    val (n, m, d) = readInts()
    val c = readInts().toIntArray()
    if (d - 1 + c.sumBy { it + d - 1 } < n) {
        println("NO")
    } else {
        println("YES")
        val space = IntArray(d - 1) { 0 }
        val ans = c.mapIndexed { index, value -> IntArray(value) { index + 1 } }.fold(space) { acc, ints -> acc + ints + space }.toMutableList()
        var extra = ans.size - n
        println(ans.filter{ !(it == 0 && extra --> 0) }.joinToString(" "))
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }