private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() }  // list of doubles

fun main() {
   var N = readInt()
   var ans = IntArray(N)
   for (i in 1..N) {
      ans[i-1] = 1 - (N / i)
   }
   for (i in 1..N) {
      var j = i * 2
      while (j <= N) {
         ans[j-1] ++
         j += i
      }
   }
   ans.sortDescending()
   for (i in 1..N-1) ans[i] += ans[i-1]
   println(ans.joinToString(" "))
}