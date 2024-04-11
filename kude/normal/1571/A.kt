private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    val s = readLn()
    var x = 0
    for(c in s) {
        if (c == '>') x = x or 1
        else if (c == '<') x = x or 2
    }
    println(if (x == 0) '=' else if (x == 1) '>' else if (x == 2) '<' else '?')
}

fun main() {
    val tt = readInt()
    repeat(tt) { solve() }
}