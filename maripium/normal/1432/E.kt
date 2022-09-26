// ecnerwala's template
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
      var (N, K) = readLongs()
      var S = readLn()
      var cnt = 0
      var bruh = mutableListOf<Int>()
      for (c in S) {
         if (c == '1') cnt++
         else bruh.add(cnt)
      }
      var M = bruh.size
      for (i in 0..M-1) {
         if (K >= bruh[i]) {
            K -= bruh[i]
            bruh[i] = 0
         } else {
            bruh[i] -= K.toInt()
            K = 0L
         }
      }
      var ans = CharArray(N.toInt())
      var it = 0
      for (i in 0..M-1) {
         while (it < bruh[i]+i) ans[it++] = '1'
         ans[it++] = '0'
      }
      while (it < N) ans[it++] = '1'
      outputLn(ans.joinToString(""))
  }
  println(OUTPUT_LINES.joinToString("\n"))
}