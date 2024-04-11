// ecnerwala's template
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun solve() {
  var (N, K) = readInts()
  var X = N / (K * K * K + K * K + K + 1)
  var Y = X * K
  var Z = Y * K
  var T = Z * K
  outputLn("$X $Y $Z $T")
}

fun main() {
   val T = readInt()
   for (t in 0..T-1) solve()
   println(OUTPUT_LINES.joinToString("\n"))
}