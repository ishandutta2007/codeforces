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
  var (N, M, Q) = readInts()
  var A = MutableList(N) { mutableListOf<Int>()}
  var rowSum = MutableList(N) { 0L }
  var colSum = MutableList(M) { 0L }
  for (i in 0..N-1) {
   A[i] = readInts().toMutableList()
  }
  var all = 0L
  for (i in 0..N-1) {
   for (j in 0..M-1) {
      rowSum[i] += A[i][j].toLong()
      colSum[j] += A[i][j].toLong()
      all += A[i][j].toLong()
   }
  }
  fun query(): Long {
   var cur = 0L
   var row = 0
   var col = 0
   for (i in 0..N-1) {
      cur += rowSum[i];
      if (cur * 2 >= all) {
         row = i
         break
      }
   }
   cur = 0L
   for (i in 0..M-1) {
      cur += colSum[i]
      if (cur * 2 >= all) {
         col = i
         break
      }
   }
    var ans = 0L
   for (i in 0..N-1) ans += abs(i - row).toLong() * rowSum[i]
   for (i in 0..M-1) ans += abs(i - col).toLong() * colSum[i]
   return ans
  }
  var kek = mutableListOf<Long>()
  kek.add(query())
  for (i in 0..Q - 1) {
      var(x, y, z) = readInts()
      --x
      --y
      rowSum[x] -= A[x][y].toLong()
      colSum[y] -= A[x][y].toLong()
      all -= A[x][y].toLong()
      A[x][y] = z
      rowSum[x] += A[x][y].toLong()
      colSum[y] += A[x][y].toLong()
      all += A[x][y].toLong()
      kek.add(query())
  }
  outputLn(kek.joinToString(" "))
  println(OUTPUT_LINES.joinToString("\n"))
}