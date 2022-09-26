// ecnerwala's template
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun solve() {
  var (N, M, K) = readInts()
  var dp = MutableList(N){1000100100}
  dp[K - 1] = 0
  for (i in 0..M-1) {
      var (x, y) = readInts()
      --x
      --y
      var oldX = dp[x]
      var oldY = dp[y]
      dp[x] = minOf(oldX + 1, oldY)
      dp[y] = minOf(oldY + 1, oldX)
  }
  for (i in 0..N - 1) {
   if (dp[i] > M) dp[i] = -1
  }
  outputLn(dp.joinToString(" "))
}

fun main() {
   val T = 1
   for (t in 0..T-1) solve()
   println(OUTPUT_LINES.joinToString("\n"))
}