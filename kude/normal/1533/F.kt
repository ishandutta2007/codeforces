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
    val s = readLn().toCharArray()
    val n = s.size
    val d0 = Array(n + 1) {0}
    val d1 = Array(n + 1) {0}
    for(i in 0 until n) {
        d0[i + 1] = d0[i]
        d1[i + 1] = d1[i]
        if (s[i] == '0') {
            d0[i + 1]++
        } else {
            d1[i + 1]++
        }
    }
    val ans = ArrayList<Int>()
    for(k in 1..n) {
        var cnt = 0
        var now = 0
        while(now < n) {
            var l = minOf(now + k, n)
            var r = n + 1
            // [l, r)
            while(r - l > 1) {
                val mid = (r + l) / 2
                if (d0[mid] - d0[now] <= k || d1[mid] - d1[now] <= k) {
                    l = mid
                } else {
                    r = mid
                }
            }
            cnt++
            now = l
        }
        ans.add(cnt)
    }
    println(ans.joinToString(" "))
}