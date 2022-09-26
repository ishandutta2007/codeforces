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
        val N = readInt()
        var ans = 0
        val A = readInts();
        for (i in 0 until N - 1) {
            if ((A[i + 1] - A[i]) % 2 == 0) {
                ans = 1
            }
        }
        if (ans == 1) {
            println("YES")
        } else {
            println("NO")
        }
    }
}