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
var b = mutableListOf<Int>()
var n = 0

fun testcover(x: Int) : Boolean {
    var tot = 0
    for (i in 0 until n) {
        if (a[i] <= x && b[i] >= x)
            tot++
    }
    return tot == 1
}


fun main() {
    var t = readInt()
    while (t > 0) {
        t--
        n = readInt()
        a.clear()
        b.clear()
        for (i in 0 until n) {
            var x = readInts()
            a.add(x[0])
            b.add(x[1])
        }
        var ans = -1
        for (i in 0 until n) {
            if (testcover(a[i] - 1)) {
                ans = a[i] - 1
                break
            }
            if (testcover(a[i])) {
                ans = a[i]
                break
            }
            if (testcover(b[i])) {
                ans = b[i]
                break
            }
            if (testcover(b[i] + 1)) {
                ans = b[i] + 1
                break
            }
        }
        println(ans)
    }
}