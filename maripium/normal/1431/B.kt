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
      var S = readLn().toCharArray()
      var N = S.size
      var ans = 0
      var used = IntArray(N)
      for (i in 0..N-1) {
         if (S[i] == 'w') {
            ans++
         } else if (i > 0 && S[i-1] == 'v' && used[i-1] == 0) {
            used[i] = 1
            ans++
         }
      }
      outputLn("$ans")
  }
  println(OUTPUT_LINES.joinToString("\n"))
}