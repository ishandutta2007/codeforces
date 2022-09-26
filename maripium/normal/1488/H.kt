private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() }  // list of doubles

const val MOD = 998244353
data class Num (var v: Int = 0) {
    constructor (lv: Long) : this((lv % MOD).toInt()) { }
    init {
        v %= MOD
        if (v < 0) v += MOD
    }
    operator fun plus(o: Num): Num {
        return Num(v + o.v)
    }
    operator fun minus(o: Num): Num {
        return Num(v - o.v)
    }
    operator fun times(o: Num): Num {
        return Num(v.toLong() * o.v.toLong())
    }
}


fun main() {
   var (N, Q) = readInts()
   var A = readInts().toMutableList()
   A.add(0)
   
   var tree = Array(4 * N) { Array(4) { Array(4) { Num(0) } } }
   
   fun pop(v: Int, l: Int, r: Int) {
      var md = (l + r) / 2
      tree[v] = Array(4) { Array(4) { Num(0) } }
      for (lv in 0..3) {
         for (mv in 0..3) if (tree[2 * v][lv][mv].v > 0) {
            var l = 0
            var r = 0
            if (A[md] == 0) {
               l = 0
               r = mv
               if (A[md+1] == 1) r --
            } else {
               l = mv
               r = 3
               if (A[md+1] == 0) l++
            }
            for (m2v in l..r) {
               for (rv in 0..3) if (tree[2 * v + 1][m2v][rv].v > 0) {
                  tree[v][lv][rv] += tree[2 * v][lv][mv] * tree[2 * v + 1][m2v][rv]
               }
            }
         }
      }
   }
   
   fun build(v: Int, l: Int, r: Int) {
      if (l == r) {
         for (i in 0..3) {
            tree[v][i][i] = Num(1)
         }
         return
      }
      var md = (l + r) / 2
      build(2 * v, l, md)
      build(2 * v + 1, md + 1, r)
      pop(v, l, r)
   }
   
   fun modify(v: Int, l: Int, r: Int, i: Int) {
      if (l == r) return
      var md = (l + r) / 2
      if (i <= md) modify(2 * v, l, md, i)
      else modify(2 * v + 1, md + 1, r, i)
      pop(v, l, r)
   }
   
   build(1, 0, N-1)
   for (q in 0..Q-1) {
      var i = readInt() - 1
      A[i] = 1 - A[i]
      modify(1, 0, N-1, i)
      var ans = Num(0)
      for (i in 0..3) {
         for (j in 0..3) {
            ans += tree[1][i][j]
         }
      }
      println(ans.v)
   }
}