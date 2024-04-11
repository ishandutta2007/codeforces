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
        var (n, s) = readLongs()
        var l = 1L
        var r = s + 1L
        while(r - l > 1L) {
            var c = (l + r) / 2
            var now: Long = c
            var sm: Long = 0L
            var rest = n
            while(rest > 0) {
                sm += now
                now = (now + 1) / 2
                rest--
                if (now == 1L) {
                    sm += rest
                    break
                }
            }
            if (sm <= s) l = c
            else r = c
        }
        println(l)
    }
}