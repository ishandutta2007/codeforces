private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val S = readLn()
    val N = S.length
    var pref0 = IntArray(N + 1) { 0 }
    var pref1 = IntArray(N + 1) { 0 }
    for (i in 0 until N) {
        pref0[i + 1] = pref0[i]
        pref1[i + 1] = pref1[i]
        if (S[i] == '0') {
            pref0[i + 1] ++
        } else {
            pref1[i + 1] ++
        }
    } 
    var ans = IntArray(N) { 0 }
    for (k in 1 until N+1) {
        var cur = 0
        while (cur < N) {
            ans[k - 1] ++;
            var lo = cur + 1
            var hi = N
            while (lo < hi) {
                val mi = (lo + hi + 1) / 2
                val c0 = pref0[mi] - pref0[cur]
                val c1 = pref1[mi] - pref1[cur]
                if (c0 <= k || c1 <= k) {
                    lo = mi
                } else {
                    hi = mi - 1
                }
            }
            cur = lo
        }
    }
    println(ans.joinToString(" "))
}