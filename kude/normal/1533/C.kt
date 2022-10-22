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
    var tt = readInt()
    for (qq in 0 until tt) {
        var (n, k) = readInts()
        val s = readLn()
        val d = ArrayList<Int>((0 until n).map{it})
        var cnt = 0
        for(c in s) if (c == '1') cnt++
        var nxt = 0
        var ans = 0
        while(cnt > 0) {
            nxt %= d.size
            val i = d[nxt]
            d.removeAt(nxt)
            ans++
            if (s[i] == '1') cnt--
            nxt += k - 1
        }
        println(ans)
    }
}