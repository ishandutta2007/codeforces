import java.lang.Integer.*

fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readLong() = readLn().toLong() // single long
fun readDouble() = readLn().toDouble() // single double
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
fun readLongs() = readStrings().map { it.toLong() } // list of longs
fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var aa = readInts()
    var n = aa[0]
    var w = aa[1]
    val a = readInts()

    var l = 0
    var r = 0
    var cur = 0
    for (i in 0 until n) {
        cur += a[i]
        l = min(l, cur)
        r = max(r, cur)
    }
    var ans = max(0, w + 1 - (r - l))
    println(ans)
}