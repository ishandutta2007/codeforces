private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() }  // list of doubles

fun main() {
   var T = readInt()
   for (tc in 1..T) {
      var (N, X, Y) = readInts()
      if (X > Y) {
         var Z = X
         X = Y
         Y = Z
      }
      var ans = 100 * N
      for (m in X..Y-1) {
         var vx = m-1 + minOf(m-X, X-1)
         var vy = N-m-1 + minOf(N-Y, Y-m-1)
         ans = minOf(ans, maxOf(vx, vy))
      }
      println("$ans")
   }
}