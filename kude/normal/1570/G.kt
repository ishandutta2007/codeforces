private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    println("? " + Array(100){it + 1}.joinToString(" "))
    var ans = readInt() shr 7 shl 7
    println("? " + Array(100){it shl 7}.joinToString(" "))
    ans = ans or (readInt() and ((1 shl 7) - 1))
    println("! $ans")
}

fun main() {
    val tt = 1
    repeat(tt) { solve() }
}