private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
   var N = readInt()
   if (N < 4) { 
      outputLn("-1") 
      return
   }
   var start = (N - 1) / 2 * 2 + 1
   var ans = mutableListOf<Int>()
   for (z in start.downTo(1).step(2)) ans.add(z)
   ans.add(4)
   ans.add(2)
   for (z in 6.rangeTo(N).step(2)) ans.add(z)
   outputLn(ans.joinToString(" "))
}

fun main() {
   val T = readInt()
   for (t in 0..T-1) go()
   println(OUTPUT_LINES.joinToString("\n"))
}