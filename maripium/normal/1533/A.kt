private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val T = readInt();
    for (t in 0 until T) {
        val (N, K) = readInts()
        var ans = 0;
        for (i in 0 until N) {
            var (L, R) = readInts();
            if (L <= K) ans = maxOf(ans, R - K + 1)
        }
        println(ans)
    }
}