import java.lang.Integer.*
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles



data class P(val first: Int, val second: Int) : Comparable<P> {
    override fun compareTo(p: P) = when {
        first < p.first -> -1
        first > p.first -> 1
        else -> second.compareTo(p.second)
    }
}


var n = 0
var m = 0
var a = mutableListOf<Pair<Int, Pair<Int, Int>>>()
var q = PriorityQueue<P>()

var ti = IntArray(size=202022, init={0})

fun work() {
    var ii = readInts()
    n = ii[0]
    m = ii[1]
    a.clear()
    for (i in 0 until n) {
        ii = readInts()
        a.add(Pair(i, Pair(ii[0], ii[1])))
    }
    a.sortBy { it.second.first }
    var curT = 0
    var ans = 0
    var i = 0
    var j = 0
    while (i < n) {
        j = i
        while (j < n && a[j].second.first == a[i].second.first) j++
        while (curT < a[i].second.first && q.size > 0) {
            var can = m
            while (q.size > 0 && can > 0) {
                var x = q.poll()
                ans = max(ans, curT - x.first)
                ti[x.second] = curT
                can--
            }
            curT++
        }
        curT = a[i].second.first

        while (i < j) {
            q.add(P(a[i].second.second, a[i].first))
            i++
        }
    }
    while (q.size > 0) {
        var can = m
        while (q.size > 0 && can > 0) {
            var x = q.poll()
            ans = max(ans, curT - x.first)
            ti[x.second] = curT
            can--
        }
        curT++
    }
    println(ans)
    for (i in 0 until n) {
        print("${ti[i]} ")
    }
    println()
}

fun main() {
    var t = readInt()
    while (t > 0) {
        t--
        work()
    }
}