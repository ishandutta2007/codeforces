import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    val n = readInt()
    val a = readInts().sorted()
    val b = readInts().sorted()
    val d_l = Array<Int>(n + 1){-1001001001}
    val d_r = Array<Int>(n + 1){-1001001001}
    for(i in 0 until n) {
        d_l[i + 1] = maxOf(d_l[i], b[i] - a[i])
    }
    for(i in n - 1 downTo 0) {
        d_r[i] = maxOf(d_r[i + 1], b[i + 1] - a[i])
    }
    val m = readInt()
    val c = readInts()
    val ans = Array(m){0}
    for(i in 0 until m) {
        val x = c[i]
        var l = -1
        var r = n
        while(r - l > 1) {
            val mid = (r + l) / 2
            if (a[mid] >= x) {
                r = mid
            } else {
                l = mid
            }
        }
        ans[i] = maxOf(d_l[r], b[r] - x, d_r[r])
    }
    println(ans.joinToString(" "))
}