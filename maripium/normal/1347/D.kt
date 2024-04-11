private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
   var N = readInt()
   var Z = readInts()
   var l = 0
   var r = N - 1
   var turn = 0
   var Asum = 0
   var Bsum = 0
   var Alast = 0
   var Blast = 0
   while (l <= r) {
      turn++
      Alast = 0
      while (l <= r && Alast <= Blast) {
          Alast += Z[l]
          Asum += Z[l++] 
      }
      if (l > r) break 
      turn++
      Blast = 0
      while (l <= r && Blast <= Alast) {
          Blast += Z[r]
          Bsum += Z[r--]
      }
   }
   outputLn("$turn $Asum $Bsum")
}

fun main() {
   val T = readInt()
   for (t in 0..T-1) go()
   println(OUTPUT_LINES.joinToString("\n"))
}