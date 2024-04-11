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
      var N = readInt()
      var A = readInts().toMutableList()
      for (i in 0..N-1) A[i] --
      var loc = IntArray(N) {-1}
      var go = IntArray(N) {-1}
      for (i in 0..N-1) {
         if (loc[A[i]] != -1) {
            go[loc[A[i]]] = i
         }
         loc[A[i]] = i
      }
      var fenw = IntArray(N) {0}
      fun modify(_x: Int, v: Int) {
         var x = _x
         while (x >= 0) {
            fenw[x] = maxOf(fenw[x], v)
            x = (x and (x+1)) - 1
         }
      }
      fun query(_x: Int): Int {
         var x = _x
         var ans = 0
         while (x < N) {
            ans = maxOf(ans, fenw[x])
            x = x or (x+1)
         }
         return ans
      }
      var ans = 1
      for (i in 0..N-1) {
         if (go[i] != -1) {
            var cur = query(go[i]+1) + 2
            modify(go[i], cur)
            if (i + 1 < go[i]) cur ++
            ans = maxOf(ans, cur)
         }
      }
      println("$ans")
   }
}