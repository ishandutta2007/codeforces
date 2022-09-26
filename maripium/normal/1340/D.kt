private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
 
private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun solve() {
   var N = readInt()
   var adj = MutableList(N) {mutableListOf<Int>()}
   for (i in 0..N-2) {
      var (x, y) = readInts()
		x -= 1
		y -= 1
		adj[x].add(y)
		adj[y].add(x)
   }
   var ans = mutableListOf<Pair<Int, Int>>()
   fun dfs(v: Int, p: Int, tm: Int) {
		ans.add(v to tm)
		var go = adj[v].size
		var flag = false
		var cur = tm
		for (u in adj[v]) {
			if (u == p) continue
			if (flag == false && cur >= go) {
				flag = true
				cur -= go
				ans.add(v to cur)
			}
			cur++
			dfs(u, v, cur)
			ans.add(v to cur)
		}
		if (flag == false && cur >= go) {
			cur -= go
			ans.add(v to cur)
		}
   }
   dfs(0, 0, 0)
   ans.removeAt(ans.size - 1)
   outputLn("${ans.size}")
   for (z in ans) outputLn("${z.first + 1} ${z.second}")
}

fun main() {
   val T = 1
   for (t in 0..T-1) solve()
   println(OUTPUT_LINES.joinToString("\n"))
}