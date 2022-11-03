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
    val l = nextDouble()

    val xs = DoubleArray(n + 1)
    val bs = DoubleArray(n + 1)

    for (i in 1 until xs.size) {
        xs[i] = nextDouble()
        bs[i] = nextDouble()
    }

    var bl = 0.toDouble()
    var br = 1e4

    val d = DoubleArray(n + 1)

    for (it in 0 until 100) {
        val m = (bl + br) / 2

        for (i in 1 until d.size) {
            d[i] = 1e9
            for (j in 0 until i) {
                d[i] = min(d[i], d[j] + sqrt(abs(xs[i] - xs[j] - l)) - m * bs[i])
            }
        }

        if (d[n] <= 0) {
            br = m
        } else {
            bl = m
        }
    }

    val p = IntArray(n + 1, { -1 })
    val m = (bl + br) / 2

    for (i in 1 until d.size) {
        d[i] = 1e9
        for (j in 0 until i) {
            val c = d[j] + sqrt(abs(xs[i] - xs[j] - l)) - m * bs[i]
            if (c < d[i]) {
                d[i] = c
                p[i] = j
            }
        }
    }

    val ans = ArrayList<Int>()
    var x = n
    while (x != -1) {
        ans.add(x)
        x = p[x]
    }

    ans.reverse()
    for (i in 1 until ans.size) {
        print(ans[i])
        print(" ")
    }
}