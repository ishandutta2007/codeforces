private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun solve() {
    val n = readInt()
    val a = readInts().toIntArray()
    val ord = Array<Int>(n) { it }
    ord.sortByDescending { a[it] }
    var ans: Long = 0
    for((x, i) in ord.withIndex()) {
        ans += x * a[i] + 1
    }
    println(ans)
    println(ord.map{it + 1}.joinToString(" "))
}

fun main() {
    val tt = 1
    repeat(tt) { solve() }
}