import java.io.*
import java.lang.AssertionError
import java.util.*
import java.lang.Math.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap

var stok = StringTokenizer("")
var br = BufferedReader(InputStreamReader(System.`in`))

fun nextToken(): String? {
    while (!stok.hasMoreTokens()) {
        val s = br.readLine() ?: return null
        stok = StringTokenizer(s)
    }
    return stok.nextToken()
}

fun nextInt() = nextToken()!!.toInt()
fun nextDouble() = nextToken()!!.toDouble()
fun nextLong() = nextToken()!!.toLong()

fun main(args: Array<String>) {
    if (args.isNotEmpty()) br = BufferedReader(FileReader("input.txt"))
    PrintWriter(System.out, false).use { it.solve() }
}

fun PrintWriter.solve() {
    val t1 = System.currentTimeMillis()

    val n = nextInt()
    val k = nextInt()

    if (n == k) {
        println(0)
        return
    }

    data class Edge(val f: Int, val to: Int): Comparable<Edge> {
        override fun compareTo(other: Edge): Int {
            val c = f.compareTo(other.f)
            if (c != 0) {
                return c
            }
            return to.compareTo(other.to)
        }
    }

    val eToId = TreeMap<Edge, Int>()
    var g = Array<ArrayList<Int>>(n, { ArrayList<Int>() })

    for (i in 1 until n) {
        val x = nextInt() - 1
        val y = nextInt() - 1
        g[x].add(y)
        g[y].add(x)
        eToId[Edge(x, y)] = i
        eToId[Edge(y, x)] = i
    }

    if (n == k + 1) {
        println(1)
        for (i in 0 until n) {
            if (g[i].size == 1) {
                println(eToId[Edge(i, g[i][0])])
                return
            }
        }
    }

    val dp = Array<IntArray>(n, { IntArray(k + 1, { 1e9.toInt() }) })
    val sz = IntArray(n)

    fun dfs(v: Int, p: Int) {
        dp[v].fill(1e9.toInt())
        dp[v][1] = g[v].size
        sz[v] = 1
        if (p != -1) {
            dp[v][1]--
        }
        for (u in g[v]) {
            if (u == p) {
                continue
            }
            dfs(u, v)
//            for (i in sz[v] + 1 .. min(k, sz[v] + sz[u])) {
//                dp[v][i] = 1e9.toInt()
//            }
            sz[v] += sz[u]
            for (i in min(k, sz[v]) downTo 2) {
                for (j in min(i - 1, sz[u]) downTo 1) {
                    dp[v][i] = min(dp[v][i], dp[v][i - j] + dp[u][j] - 1)
                }
            }
        }
    }

    dfs(0, -1)

    val t2 = System.currentTimeMillis()

    var av = -1
    var aa = 1e9.toInt()
    for (i in 0 until n) {
        val a = if (i == 0) 0 else 1
        if (dp[i][k] + a < aa) {
            aa = dp[i][k] + a
            av = i
        }
    }

    dfs(av, -1)

    var ng = Array<ArrayList<Int>>(n, { ArrayList() })

    fun ndfs(v: Int, p: Int) {
        for (u in g[v]) {
            if (u != p) {
                ng[v].add(u)
                ndfs(u, v)
            }
        }
    }

    ndfs(av, -1)
    g = ng

    val gg = Array<IntArray>(n, { i -> IntArray(ng[i].size, { j -> ng[i][j] }) })
    val ggsz = IntArray(n, { i -> ng[i].size })

    fun ggremove(i: Int, x: Int) {
        var p = 0
        while (p < ggsz[i]) {
            if (gg[i][p] == x) {
                break
            }
            p++
        }
        --ggsz[i]
        val t = gg[i][p]
        gg[i][p] = gg[i][ggsz[i]]
        gg[i][ggsz[i]] = t
    }

    fun ggrestore(i: Int) {
        ++ggsz[i]
    }

    fun dfs2(v: Int) {
        dp[v].fill(1e9.toInt())
        dp[v][1] = ggsz[v]
        sz[v] = 1
//        if (p != -1) {
//            dp[v][1]--
//        }
//        for (u in g[v]) {
        for (i in 0 until ggsz[v]) {
            val u = gg[v][i]
            dfs2(u)
            sz[v] += sz[u]
            for (i in min(k, sz[v]) downTo 2) {
                for (j in min(i - 1, sz[u]) downTo 1) {
                    dp[v][i] = min(dp[v][i], dp[v][i - j] + dp[u][j] - 1)
                }
            }
        }
    }

    val ans = ArrayList<Int>()

    for (v in 0 until n) {
        val ves = IntArray(ggsz[v], { i -> gg[v][i] })
        for (u in ves) {
//            g[v].remove(u)
            ggremove(v, u)
//            g[u].remove(v)
            dfs2(av)
            if (dp[av][k] == aa - 1) {
                ans.add(eToId[Edge(v, u)]!!)
                aa--
            } else {
//                g[v].add(u)
                ggrestore(v)
//                g[u].add(v)
            }
        }
    }

    val t3 = System.currentTimeMillis()
    System.err.println(t2 - t1)
    System.err.println(t3 - t2)

    println(ans.size)
    for (i in ans) {
        print(i)
        print(" ")
    }

    val t4 = System.currentTimeMillis()
    System.err.println(t4 - t1)
}