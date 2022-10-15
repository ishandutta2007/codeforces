import java.lang.Integer.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var a = mutableListOf<Int>()
var b = mutableListOf<Pair<Int, Int>>()

fun main() {
    var t = readInt()
    while (t > 0) {
        t--
        var ii = readInts()
        var n = ii[0]
        var k = ii[1]
        a = readInts().toMutableList()
        b.clear()
        for (i in 0 until n) {
            b.add(Pair(a[i], i))
        }
        b.sortBy { it.first }
        var sum = 0.toLong()
        for (i in a) sum += i
        var l = b[n - 1].first
        var r = l + k
        while (l < r) {
            var mid = ((l.toLong() + r) / 2).toInt()
            var ss = (mid.toLong() + mid - n + 1) * n / 2 - sum
            if (ss >= k) r = mid
            else l = mid + 1
        }
//        println("l = $l")
        var d = IntArray(n, {0})
        for (i in n - 1 downTo 0) {
            var delta = min(l + i - (n - 1) - b[i].first, k)
            d[b[i].second] = delta
            k -= delta
        }
        for (i in 0 until n){
            print("${d[i]} ")
        }
        println();
    }
}