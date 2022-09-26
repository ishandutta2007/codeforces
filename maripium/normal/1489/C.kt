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
   var N = readInt()
   var S = readLn()
   var i = 0
   var ans = 0
   while (i < N) {
      while (i < N && S[i] != 'x') i++;
      if (i == N) break
      var len = 0
      while (i < N && S[i] == 'x') {
         i++
         len++
      }
      ans += maxOf(len - 2, 0)
   }
   println(ans)
}