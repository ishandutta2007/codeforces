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
    var s = nextToken()!!

    var aa = -1
    var sa = ""

    for (c1 in 'A'..'Z') {
        for (c2 in 'A'..'Z') {
            var cnt = 0
            for (i in 1 until s.length) {
                if (s[i - 1] == c1 && s[i] == c2) {
                    cnt++
                }
            }
            if (cnt > aa) {
                aa = cnt
                sa = c1.toString() + c2;
            }
        }
    }

    println(sa)
}