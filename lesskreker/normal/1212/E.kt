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
    data class Group(val c: Int, val p: Int, val id: Int): Comparable<Group> {
        override fun compareTo(other: Group): Int {
            return p.compareTo(other.p)
        }
    }
    data class Table(val r: Int, val id: Int): Comparable<Table> {
        override fun compareTo(other: Table): Int {
            return r.compareTo(other.r)
        }
    }

    val n = nextInt()
    val gs = ArrayList<Group>()
    for (i in 0 until n) {
        val c = nextInt()
        val p = nextInt()
        gs.add(Group(c, p, i))
    }

    val k = nextInt()
    val ts = ArrayList<Table>()
    for (i in 0 until k) {
        val r = nextInt()
        ts.add(Table(r, i))
    }

    gs.sort()
    gs.reverse()
    ts.sort()

    var s = 0
    val ans = ArrayList<Pair<Int, Int>>()
    val used = BooleanArray(k)
    for (i in 0 until n) {
        var p = -1
        for (j in 0 until k) {
            if (!used[j] && ts[j].r >= gs[i].c) {
                p = j
                break
            }
        }
        if (p != -1) {
            s += gs[i].p
            used[p] = true
            ans.add(Pair(gs[i].id, ts[p].id))
        }
    }

    print(ans.size)
    print(" ")
    println(s)
    for (p in ans) {
        print(p.first + 1)
        print(" ")
        println(p.second + 1)
    }
}