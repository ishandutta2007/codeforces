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
      val N = readInt()
      var A = readInts()
      var tot = 0
      for (a in A) tot += a
      outputLn("${(tot+N-1)/N}")
  }
  println(OUTPUT_LINES.joinToString("\n"))
}