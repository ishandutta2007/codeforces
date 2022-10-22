import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() - 1 } // list of ints
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
        var n = readInt()
        var a = readInts()
        var ans = 1
        val idx = Array(n){-1}
        val pairIdx = Array(n) {-1}
        for(i in 0 until n) {
            val j = idx[a[i]]
            if (j != -1) {
                pairIdx[j] = i
                pairIdx[i] = j
            } else {
                idx[a[i]] = i
            }
        }
        val d = MutableList<Int>(0){0}
        for(i in 0 until n) {
            val j = pairIdx[i]
            if (j == -1 || j < i) continue
            var l: Int = -1
            var r: Int = d.size
            while(r - l > 1) {
                val c = (l + r) / 2
                //println("$l $c $r")
                if (d[c] <= j) r = c
                else l = c
            }
            if (r < d.size) {
                d[r] = j
            } else {
                d.add(j)
            }
            if (i + 1 < j) ans = maxOf(ans, 2 * (r + 1) + 1)
            else ans = maxOf(ans, 2 * (r + 1))
            //println(d.joinToString(" "))
        }
        println(ans)
    }
}