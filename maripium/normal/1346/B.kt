// ecnerwala's template
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun solve() {
  var (N, K1, K2) = readInts()
  var S = readLn().toCharArray()
  if (N == 1) {
      if (S[0] == '0') outputLn("0")
      else outputLn("$K1")
      return
  }
  var i = 0
  var ans = 0
  K1 = minOf(K1, K2)
  K2 = minOf(K1 * 2, K2)
  while (i < N) {
      while (i < N && S[i] == '0') i++
      if (i == N) break
      var len = 0
      while (i < N && S[i] == '1') {
         i++
         len++
      }
      // outputLn("length $len")
      ans += (len / 2) * K2 + (len % 2) * K1
  }
  outputLn("$ans")
}

fun main() {
   val T = readInt()
   for (t in 0..T-1) solve()
   println(OUTPUT_LINES.joinToString("\n"))
}