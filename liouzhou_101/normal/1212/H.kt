import java.util.*
import kotlin.math.*

private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readLong() = readString().toLong()
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

val INF = 1000000000

fun main(args: Array<String>)
{
    var (n, k) = readInts()
    var f = Array<Array<Int>>(n+1, { x -> Array<Int>(n+1, { x -> INF }) })
	var v = Array<Array<Int>>(n+1, { x -> arrayOf<Int>() })
    var e = arrayOf<Pair<Int, Int>>()
    for (i in 1..n-1)
    {
        var (x, y) = readInts()
        v[x] += arrayOf(y)
        v[y] += arrayOf(x)
        e += Pair(x, y)
    }
    
    var size = Array<Int>(n+1, {x -> 0})
    var pre = Array<Int>(n+1, {x -> 0})
    var ans = INF
    var g = Array<Array<Array<Int>>>(n+1, { x -> arrayOf<Array<Int>>() })
    var son = Array<Array<Int>>(n+1, { x -> arrayOf<Int>() })
    fun dfs(x: Int, p: Int)
    {
        size[x] = 0
        for (y in v[x])
        {
            if (y == p) continue
            pre[y] = x
            son[x] += arrayOf(y)
            dfs(y, x)
            size[x] += size[y]
        }
        size[x] ++
        
        g[x] += arrayOf(arrayOf(0))
        var cur = 0
        for (k in 1..son[x].size)
        {
            var y = son[x][k-1]
            g[x] += arrayOf(Array<Int>(cur+size[y]+1, {x -> INF}))
            for (i in 0..cur)
                for (j in 0..size[y])
            		g[x][k][i+j] = minOf(g[x][k][i+j], g[x][k-1][i]+f[y][j])
            cur += size[y]
        }
        
        for (i in 1..size[x])
            f[x][i] = g[x][son[x].size][i-1]
        f[x][0] = 1
        if (x == 1)
            ans = minOf(ans, f[x][k])
        else
            ans = minOf(ans, f[x][k]+1)
    }
    dfs(1, 0)
    println(ans)
    var x = 0
    for (i in 1..n)
    {
        if (i == 1)
        {
        	if (f[i][k] == ans) x = i
        }
        else
        {
            if (f[i][k]+1 == ans) x = i
        }
    }
    fun calc(x: Int, y: Int): Int
    {
        for (i in 0..n-2)
        {
            if (e[i].first == x && e[i].second == y) return i
            if (e[i].first == y && e[i].second == x) return i
        }
        return -1
    }
    fun solve(x: Int, sum: Int)
    {
        var s = sum-1
        var cur = size[x]-1
        for (k in son[x].size downTo 1)
        {
            var y = son[x][k-1]
            cur -= size[y]
            var t = -1
            for (i in 0..size[y])
            	if (0 <= s-i && s-i <= cur && g[x][k-1][s-i]+f[y][i] == g[x][k][s])
					t = i
            if (t == 0)
            {
                var id = calc(x, y)+1
                print("$id ")
            }
            else
            	solve(y, t)
            s -= t
        }
    }
    solve(x, k)
    if (x != 1)
    {
        var id = calc(pre[x], x)+1
        print("$id ")
    }
}