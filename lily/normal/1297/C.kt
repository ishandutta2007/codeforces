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
var n = 0


fun main() {
    var t = readInt()
    while (t > 0) {
        t--
        n = readInt()
        a = readInts().toMutableList()
        b.clear()
        for (i in 0 until n) {
            if (a[i] != 0) b.add(Pair(a[i], i))
        }
        b.sortBy{it.first}
        var ans = BooleanArray(n)
        var lo = -1
        var bs = b.size
        for (i in 0 until bs) {
            if (b[i].first <= 0) lo = i;
        }
        var l = 0
        var r = 0
        if (lo == -1) {
            l = 1
            r = bs - 1
        }
        else if (lo == bs - 1) {
            l = bs - 2
            r = bs - 2
        }
        else if (lo == bs - 2) {
            l = bs - 2
            r = bs - 1
        }
        else if (-b[lo].first >= b[lo + 1].first) {
            l = lo + 2
            r = bs - 1
        }
        else {
            l = lo
            r = bs
        }
//        println("l = $l r = $r jmp = $jmp")
        var tot = 0
        for (i in 0 until bs) {
            if (i in l..r) {
                ans[b[i].second] = true
                tot += b[i].first
            } else {
                ans[b[i].second] = false
            }
        }
        println(tot)
        for (i in 0 until n) {
            print("${if (ans[i]) 1 else 0}")
        }
        println()
    }
}