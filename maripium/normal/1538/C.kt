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
    for (tc in 0..T - 1) {
        val (N, L, R) = readInts();
        val A = readInts().sorted();
        var ans = 0L;
        fun bound(a: Int): Int {
            var lo = 0;
            var hi = N;
            while (lo < hi) {
                val mi = (lo + hi) / 2;
                if (A[mi] >= a) hi = mi;
                else lo = mi + 1;
            }
            return lo;
        }
        for (a in A) {
            if (a + a >= L && a + a <= R) ans --;
            ans += bound(R + 1 - a) - bound(L - a);
        }
        println(ans / 2);
    }
}