// ecnerwala's template
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun solve() {
  var (N, M) = readInts()
  var req = MutableList(N) { 0 }
  var adj = MutableList(N) { mutableListOf<Pair<Int, Int>>() }
  for (i in 0..M-1) {
   var (v, u, w) = readInts()
   --v
   --u
   req[v] = maxOf(req[v], w)
   req[u] = maxOf(req[u], w)
   adj[v].add(u to w)
   adj[u].add(v to w)
  }
  var fail = false
  for (v in 0..N - 1) {
   for (it in adj[v]) {
      if (minOf(req[v], req[it.first]) != it.second) {
         fail = true
      }
   }
  }
  if (fail) outputLn("NO")
  else {
   outputLn("YES")
   outputLn(req.joinToString(" "))
  }
}

fun main() {
   val T = readInt()
   for (t in 0..T-1) solve()
   println(OUTPUT_LINES.joinToString("\n"))
}