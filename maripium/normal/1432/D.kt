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
      var (N, A, B) = readInts()
      var ans = CharArray(N)
      for (i in 0..B-1) ans[i] = 'a'+i
      for (i in B..A-1) ans[i] = 'a'
      for (i in A..N-1) ans[i] = ans[i % A]
      outputLn(ans.joinToString(""))
  }
  println(OUTPUT_LINES.joinToString("\n"))
}