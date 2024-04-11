import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (a, b, c) = readInts()

    val x = 3 * min(min(a, b - 1), c - 2) + 3

    println(x)
}