import java.lang.Integer.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var aa = readInts()
    var n = aa[0]
    var w = aa[1]
    val a = readInts()

    var p = 0
    for (i in 0 until n) {
        if (a[i] == w) {
            p = i
            break
        }
    }
    var L = IntArray(n * 2 + 1, {0})
    val R = IntArray(n * 2 + 1, {0})
    var tmp = 0

    for (i in p downTo 0) {
        tmp += when {
            a[i] > w -> 1
            a[i] < w -> -1
            else -> 0
        }
        L[tmp + n] ++;
    }

    tmp = 0
    for (i in p until n) {
        tmp += when {
            a[i] > w -> 1
            a[i] < w -> -1
            else -> 0
        }
        R[tmp + n] ++;
    }
    var ans = 0.toLong()
    for (i in -(n - 1) until n) {
        ans += L[n + i].toLong() * R[n - i]
        ans += L[n + i + 1].toLong() * R[n - i]
    }
//    ans += L[1] * R[n + n]
    println(ans)
}