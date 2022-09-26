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
   val N = readInt()
   val A = readInts()
   val st = TreeSet<Int>()
   val B = mutableListOf<Int>()
   for (i in N-1 downTo 0) {
      if (st.add(A[i])) {
         B.add(A[i])
      }
   }
   B.reverse()
   println(B.size)
   println(B.joinToString(" "))
}