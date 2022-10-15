import java.lang.Integer.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var t = readInt()
    while (t > 0) {
        t--
        var n = readInt()
        if (n < 1000) println("$n")
        else if (n >= 999500) println("${(n + 500000) / 1000000}M")
        else println("${(n + 500) / 1000}K")
    }
}