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
  val T = readInt()
  for (t in 0..T-1) {
      var (N, K) = readInts()
      var A = readInts()
      var ans = 0
      for (l in 1..(N/K)) {
         var s = N - l * K
         var cur = 0
         for (i in s..s+l-1) cur += A[i]
         ans = maxOf(ans, cur)
      }
      outputLn("${ans}")
  }
  println(OUTPUT_LINES.joinToString("\n"))
}