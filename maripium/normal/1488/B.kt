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
      var (N, K) = readInts()
      var S = readLn()
      var bal = 0
      var cnt = 0
      for (i in 0..N-1) {
         if (S[i] == '(') bal++
         else bal--
         if (bal == 0) cnt ++
      }
      var ans = cnt + minOf(N/2 - cnt, K)
      println("$ans")
   }
}