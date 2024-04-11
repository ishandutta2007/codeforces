private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() }  // list of doubles

fun main() {
   var T = readInt()
   for (tc in 1..T) {
      var (N, S) = readLongs()
      var low = 1L
      var high = S
      while (low < high) {
         var mid = (low + high + 1) / 2
         var tot = 0L
         var cur = mid
         for (i in 0..N-1) {
            if (cur == 1L) {
               tot += N-i
               break
            }
            tot += cur
            cur = (cur + 1) / 2
         }
         if (tot <= S) low = mid
         else high = mid - 1
      }
      println("$low")
   }
}