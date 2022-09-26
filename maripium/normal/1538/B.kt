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
        var tot = 0L;
        for (a in A) tot += a;
        if (tot % N > 0) {
            println(-1);
            continue;
        }
        tot /= N;
        var ans = 0;
        for (a in A) if (a > tot) ans++;
        println(ans);
    }
}