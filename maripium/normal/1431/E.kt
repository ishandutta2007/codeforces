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
      var N = readInt()
      var A = readInts()
      var B = readInts()
      var best = 0
      var go = -1;
      for (s in 0..N-1) {
         var cur = 1000000000
         for (i in 0..N-1) cur = minOf(cur, abs(A[i] - B[(i+s) % N]))
         if (cur > best) {
            best = cur
            go = s
         }
      }
      var ans = mutableListOf<Int>()
      for (i in 0..N-1) ans.add((go+i)%N+1)
      outputLn(ans.joinToString(" "))
  }
  println(OUTPUT_LINES.joinToString("\n"))
}