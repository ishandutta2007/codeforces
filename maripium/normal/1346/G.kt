// ecnerwala's template

import kotlin.random.Random
import java.math.*
// import kotlin.system
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

var MX = 1000100
fun mygcd(x: Int, y: Int) : Int {
   if (x == 0 || y == 0) return x + y
   return mygcd(y, x % y)
}
fun solve() {
  var (K, N) = readInts()
  var P = readInts().toMutableList()
  var X = readInts().toMutableList()
  var go = MutableList(MX) {-1}
  for (p in P) {
   for (z in 0.rangeTo(MX - 1).step(p)) go[z] = p
  }
  var start1 = -1
  var start2 = -1
  var jump1 = -1
  var jump2 = -1
  fun kek(x: Int, p: Int) {
      var r = x % p
      var unseen = mutableListOf<Int>()
      for (x in X) {
         if (x % p != r) unseen.add(x)
      }
      if (r == 0) r = p
      if (unseen.size == 0) {
         start1 = r
         start2 = r
         jump1 = p
         jump2 = p
         return
      }
      var g = 0
      for (i in 1..unseen.size - 1) g = mygcd(g, unseen[i] - unseen[i - 1])
      if (go[g] != -1) {
         start1 = r
         start2 = unseen[0]
         jump1 = p
         jump2 = go[g]
      }
   }
  for (it in 0..25) {
   if (start1 != -1) break
      var z = Random.nextInt(0, N - 1)
      for (p in P) {
      if (start1 != -1) break
         if ((MX / p) < (N + 1) / 2) break
         kek(X[z], p)
      }
  }
  if (start1 == -1) outputLn("NO")
  else {
   outputLn("YES")
   outputLn("$start1 $jump1")
   outputLn("$start2 $jump2")
  }
}

fun main() {
   val T = 1
   for (t in 0..T-1) solve()
   println(OUTPUT_LINES.joinToString("\n"))
}