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
   var A = readInts()
   
   var sum = LongArray(4 * N) { 0L }
   var lazy = IntArray(4 * N) { -1 }
   
   fun push(v: Int, l: Int, r:Int) {
      if (lazy[v] != -1) {
         sum[v] = lazy[v].toLong() * (r - l + 1)
         if (l < r) {
            lazy[v * 2] = lazy[v]
            lazy[v * 2 + 1] = lazy[v]
         }
         lazy[v] = -1
      }
   }
   
   fun modify(v: Int, l: Int, r: Int, ql: Int, qr: Int, x: Int) {
      push(v, l, r)
      if (l > qr || r < ql) return
      if (ql <= l && r <= qr) {
         lazy[v] = x;
         push(v, l, r)
         return
      }
      var md = (l + r) / 2
      modify(v * 2, l, md, ql, qr, x)
      modify(v * 2 + 1, md + 1, r, ql, qr, x)
      sum[v] = sum[v * 2] + sum[v * 2 + 1]
   }
   
   fun query(v: Int, l: Int, r: Int, ql: Int, qr: Int): Long {
      push(v, l, r)
      if (l > qr || r < ql) return 0L
      if (ql <= l && r <= qr) return sum[v]
      var md = (l + r) / 2
      return query(v * 2, l, md, ql, qr) + query(v * 2 + 1, md+1, r, ql, qr)
   }
   var Q = readInt()
   var qs = MutableList(N) { mutableListOf<Pair<Int, Int>>() }
   for (i in 0..Q-1) {
      var (l, r) = readInts()
      l --
      r--
      qs[r].add(l to i)
   }
   
   var st = mutableListOf<Int>()
   st.add(-1)
   var ans = LongArray(Q)
   for (i in 0..N-1) {
      while (st.size > 1 && A[i] >= A[st[st.size - 1]]) st.removeAt(st.size - 1)
      modify(1, 0, N-1, st[st.size - 1] + 1, i, A[i])
      st.add(i)
      for (q in qs[i]) {
         ans[q.second] = query(1, 0, N-1, q.first, i)
      }
   }
   println(ans.joinToString(" "))
}