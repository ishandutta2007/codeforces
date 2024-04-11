private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val N = readInt()
    var A = readInts().sorted()
    var B = readInts().sorted()
    val pref = IntArray(N + 1) { -2000000000 }
    for (i in 0 until N) {
        pref[i + 1] = maxOf(pref[i], B[i] - A[i])
    }
    val suff = IntArray(N + 1) { -2000000000 }
    for (i in N.downTo(1)) {
        suff[i - 1] = maxOf(suff[i], B[i] - A[i - 1])
    }
    val Q = readInt()
    val C = readInts()
    val ans = IntArray(Q) { 0 }
    for (q in 0 until Q) {
        var lo = 0
        var hi = N
        while (lo < hi) {
            val mi = (lo + hi + 1) / 2
            if (C[q] > A[mi - 1]) {
                lo = mi 
            } else {
                hi = mi - 1
            }
        }
        ans[q] = maxOf(pref[lo], suff[lo], B[lo] - C[q])
    }
    println(ans.joinToString(" "))
}