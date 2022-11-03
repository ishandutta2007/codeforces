import java.io.*
import java.util.*
import java.lang.Math.*

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
    var n = nextInt()
    var k = nextInt()
    var a = IntArray(n);
    for (i in 0 until n) {
        a[i] = nextInt()
    }

    val rand = Random(System.nanoTime())
    for (i in 1 until n) {
        val j = rand.nextInt(i + 1)
        val x = a[i]
        a[i] = a[j]
        a[j] = x
    }
    a.sort()
    if (k == 0) {
        if (a[0] == 1) {
            println(-1)
        } else {
            println(1)
        }
    } else if (k == n) {
        print(1e9.toInt())
    } else {
        if (a[k] == a[k - 1]) {
            print(-1)
        } else {
            print(a[k - 1])
        }
    }
}