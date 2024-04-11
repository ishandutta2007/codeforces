// ecnerwala's template
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun solve() {
  var (N, K, X, Y) = readInts()
  var A = readInts().sortedDescending()
  var it = 0
  var sum = 0L
  var ans = 0
  for (i in 0..N-1) {
      if (A[i] > K) ans += X
      sum += A[i].toLong()
   }
   var limit = N.toLong() * K
   var cur = 0
   for (i in 0..N-1) {
      if (sum > limit) {
         sum -= A[i]
         cur += X
      }
   }
   cur += Y
   ans = minOf(ans, cur)
   outputLn("$ans")
}

fun main() {
   val T = readInt()
   for (t in 0..T-1) solve()
   println(OUTPUT_LINES.joinToString("\n"))
}