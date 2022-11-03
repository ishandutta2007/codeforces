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
    var n = nextLong()
    val ps = LongArray(16)
    ps[0] = 1
    for (i in 1 until ps.size) {
        ps[i] = ps[i - 1] * 10 + 1
    }

    var ans = 1e9.toInt()

    fun go(i: Int, s: Long, ca: Int, n: Long) {
        if (s == n) {
            ans = min(ans, ca)
        }
        if (i == -1 || s - 9 * ps[i] > n || s + 9 * ps[i] < n) {
            return
        }

        for (j in -9 .. 9) {
            go(i - 1, s + ps[i] * j, ca + abs(j) * (i + 1), n)
        }
    }

    go(15, 0, 0, n)

    print(ans)
}