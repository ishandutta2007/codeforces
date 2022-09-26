// ecnerwala's template
import java.util.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }
 
fun main() {
  var (N, K, X) = readInts()
  var A = readInts()
  fun solve(sum: Long): Boolean {
      var lows = PriorityQueue<Int>()
      var totLows = 0L
      var curK = 0
      for (i in 0..N-1) {
         lows.add(-A[i])
         totLows += A[i] 
         if (lows.size == X+1) {
            curK++
            totLows += lows.peek()
            lows.remove()
         }
         if (lows.size == X && totLows <= sum) {
            totLows = 0L
            while (lows.size > 0) lows.clear()
         }
      }
      while (curK < K && lows.size > 0) {
         curK++
         totLows += lows.peek()
         lows.remove()
      }
      return curK <= K && totLows <= sum
  }
  var la = 0L
  var ra = 10000000000L
  while (la < ra) {
      var ma = (la + ra) / 2
      if (solve(ma)) ra = ma
      else la = ma+1
  }
  outputLn("${la}")
   println(OUTPUT_LINES.joinToString("\n"))
}