import java.util.Scanner
import java.util.Arrays
import java.util.ArrayList

object Solution {
    var MOD = 1000 * 1000 * 1000 + 7
    var d: Integer = null
    var used: Array[Boolean] = null
    var graph: Array[ArrayList[Integer]] = null
    var a: Array[Integer] = null
    
    def bad(a1: Integer, i1: Integer, a2: Integer, i2: Integer): Boolean = {
	return (a1 < a2 || a1 == a2 && i1 < i2 || a1 - a2 > d)
    }
    
    def dfs(v: Integer, root: Integer): Long = {
	if (bad(a(v), v, a(root), root))
	    return 1
	used(v) = true
	var res: Long = 1
	var index = 0
	for (index <- 0 until graph(v).size()) {
	    val to = graph(v).get(index)
	    if (!used(to))
		res = res * dfs(to, root) % MOD
	}
	return res + 1
    }
    
    def main(args: Array[String]) = {
	val in = new Scanner(System.in)
	d = in.nextInt()
	val n = in.nextInt()
	a = new Array(n)
	graph = new Array(n)
	var i = 0
	for (i <- 0 until n) {
	    graph(i) = new ArrayList()
	    a(i) = in.nextInt()
	}
	for (i <- 0 until n - 1) {
	    val from = in.nextInt()
	    val to = in.nextInt()
	    graph(from - 1).add(to - 1)
	    graph(to - 1).add(from - 1)
	}
	var res: Long = 0
	used = new Array(n)
	for (i <- 0 until n) {
	    Arrays.fill(used, false)
	    res = (res + dfs(i, i) - 1 + MOD) % MOD
	}
	println(res)
    }
}