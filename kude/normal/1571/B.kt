private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    val n = readInt()
    val (a, va) = readInts()
    val (c, vc) = readInts()
    val b = readInt()
    val ans = maxOf(va, vc - (c - b))
    println(ans)
}

fun main() {
    val tt = readInt()
    repeat(tt) { solve() }
}