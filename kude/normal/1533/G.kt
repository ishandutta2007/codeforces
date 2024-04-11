import com.sun.xml.internal.fastinfoset.algorithm.BooleanEncodingAlgorithm
import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    var tt = readInt()
    for (qq in 0 until tt) {
        val (n, m) = readInts()
        val a = Array<Array<Int>>(n) {Array<Int>(m){0} }
        for(i in 0 until n) {
            val t = readInts()
            for(j in 0 until m) {
                a[i][j] = t[j]
            }
        }
        val visited = Array<Array<Boolean>>(n){Array<Boolean>(m){false}}
        var ri = -1
        var rj = -1
        for(i in 0 until n) {
            for(j in 0 until m) {
                if (a[i][j] > 0) {
                    ri = i
                    rj = j
                    break
                }
                if (ri >= 0) break
            }
        }
        val tour = ArrayList<Pair<Int, Int>>()
        val di = arrayOf(1, 0, -1, 0)
        val dj = arrayOf(0, 1, 0, -1)
        fun dfs(i: Int, j: Int, pi: Int, pj: Int): Unit {
            tour.add(Pair(i, j))
            for(k in 0 until 4) {
                val ni = i + di[k]
                val nj = j + dj[k]
                if (!((ni != pi || nj != pj) && 0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] > 0 && !visited[ni][nj])) continue
                visited[ni][nj] = true
                dfs(ni, nj, i, j)
                tour.add(Pair(i, j))
            }
        }
        visited[ri][rj] = true
        dfs(ri, rj, -5, -52)
        var ok = true
        var k = 0
        for(i in 0 until n) {
            for(j in 0 until m) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    ok = false
                }
                if (a[i][j] > 0) k++
            }
        }
        if (!ok) {
            println(-1)
            continue
        }
//        val ans = ArrayList<Array<Int>>()
        val z = tour.size
        println("$k $k")
        for(i in 0 until k) {
            val t = Array<Int>(k){0}
            for(j in 0 until k) {
                val (x, y) = tour[i + j]
                t[j] = a[x][y]
            }
            println(t.joinToString(" "))
        }
    }
}