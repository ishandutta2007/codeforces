import java.io.*
import java.util.*
import java.lang.Math.*
import kotlin.collections.ArrayList

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
    val n = nextInt()
    val a = LongArray(n)
    for (i in 0 until n) {
        a[i] = nextLong()
    }
    val g = Array<ArrayList<Int>>(n, { ArrayList() })
    for (i in 0 until n) {
        for (j in 0 until n) {
            if (a[i] * 2 == a[j] || a[j] * 3 == a[i]) {
                g[i].add(j);
            }
        }
    }

    val used = IntArray(n)
    val ts = ArrayList<Int>()

    fun dfs(v: Int) {
        used[v] = 1
        for (i in g[v]) {
            if (used[i] == 0) {
                dfs(i)
            }
        }
        ts.add(v)
    }

    for (i in 0 until n) {
        if (used[i] == 0) {
            dfs(i)
        }
    }

    ts.reverse()
    for (i in ts) {
        print(a[i])
        print(" ")
    }
}