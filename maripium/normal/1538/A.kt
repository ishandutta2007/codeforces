private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var T = readInt();
    for (tc in 0..T - 1) {
        var N = readInt();
        var A = readInts();
        var l = -1;
        var r = -1;
        for (i in 0..N - 1) {
            if (A[i] == 1 || A[i] == N) {
                if (l == -1) l = i;
                else r = i;
            }
        }
        println(minOf(r + 1, N - l, N - (r - l - 1)));
    }
}