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
        var (n, x_, y_) = readInts()
        val x: Int = minOf(x_, y_)
        val y: Int = maxOf(x_, y_)
        var l = -1
        var r = 2 * n
        while(r - l > 1) {
            val c: Int = (l + r) / 2
            //println("$l, $c, $r")
            if (!(x - 1 <= c && n - y <= c)) {
                l = c
                continue
            }
            val p1 = maxOf(c - (x - 1) + 1, (c + x + 1) / 2)
            val p2 = minOf(n - (c - (n - y)), (y + n - c + 1) / 2)
            //println("p1: $p1, p2: $p2")
            if (p1 + 1 >= p2) r = c
            else l = c
        }
        println(r)
    }
}