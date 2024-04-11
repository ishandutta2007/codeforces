import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() }  // list of doubles

fun main() {
   var Q = readInt()
   for (q in 0..Q-1) {
      var (N, A, B) = readLongs()
      B = minOf(B, 2 * A)
      println((N / 2) * B + (N % 2) * A)
   }
}