// ecnerwala's template
import kotlin.math.abs
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }
 
fun main() {
  var (N, K) = readInts()
  var A = readInts().toMutableList()
  A.sort()
  var pref = mutableListOf<Int>()
  pref.add(0)
  for (a in A) pref.add(pref[pref.size - 1] + a)
  var dp = Array(N+1, {IntArray(K+1, {0})})
  for (i in 0..N-1) {
      for (j in 0..K) {
         dp[i+1][j] = maxOf(dp[i+1][j], dp[i][j])
         for (s in 1..minOf(K-j, (N-i)/2)) {
            dp[i+2*s][j+s] = maxOf(dp[i+2*s][j+s], dp[i][j] + (pref[i+s+s]-pref[i+s]) - (pref[i+s] - pref[i]))
         }
      }
   }
   outputLn("${dp[N][K]}")
  println(OUTPUT_LINES.joinToString("\n"))
}