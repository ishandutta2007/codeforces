import java.lang.Integer.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var a = mutableListOf<Int>()
var E = List<MutableList<Int>>(size=300005, init={mutableListOf<Int>()})
var k = 0
var n = 0
var leaf = 0
var vis = BooleanArray(size=300005)


fun dfs(x:Int, fa:Int) {
    for (v in E[x]) if (v != fa) {
        dfs(v, x)
    }
    if (E[x].size == 1) leaf++
}

fun solve(x: Int, fa: Int) {
    vis[x] = k > 0
    if (E[x].size == 1) k --
    for (v in E[x]) if (v != fa) {
        solve(v, x)
    }
}

fun main() {
    var t = readInt()
    while (t > 0) {
        t--
        var ii = readInts()
        n = ii[0]
        k = ii[1]
        for (i in 1..n) E[i].clear()
        for (i in 1 until n) {
            ii = readInts()
            E[ii[0]].add(ii[1])
            E[ii[1]].add(ii[0])
        }
        if (n == 2) {
            println("Yes")
            println(k)
            for (i in 1..k) print("$i ")
            println()
        }
        else {
            var rt = -1
            for (i in 1..n) if (E[i].size > 1) {
                rt = i
                break
            }
            leaf = 0
            dfs(rt, -1)
//            println("leaf = $leaf")
            if (k == 1) {
                print("Yes\n1\n1\n")
            }
            else if (leaf >= k) {
                for (i in 1..n) vis[i] = false
                for (i in 1..n) if (E[i].size == 1) {
                    rt = i
                    break
                }
                solve(rt, -1)
                var cnt = 0
                for (i in 1..n) if (vis[i]) cnt++
                print("Yes\n${cnt}\n")
                for (i in 1..n) if (vis[i]) print("${i} ");
                println()
            }
            else {
                println("No")
            }
        }
    }
}