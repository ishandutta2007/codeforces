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
        var (X, Y, A, B) = readInts();
        if (A > B) {
            A = B.also{ B = A };
        }
        B -= A;
        var lo = 0;
        var hi = minOf(X, Y) / A;
        fun is_good(mi: Int): Boolean {
            var _X = X - A * mi;
            var _Y = Y - A * mi;
            var tot = mi;
            if (B > 0) tot = (_X / B) + (_Y / B);
            return tot >= mi;
        }

        while (lo < hi) {
            var mi = (lo + hi + 1) / 2;
            if (is_good(mi)) lo = mi;
            else hi = mi - 1;
        }
        println(lo);
    }
}