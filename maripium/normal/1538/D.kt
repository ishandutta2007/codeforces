private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun gcd(a: Int, b: Int): Int {
    if (a == 0 || b == 0) return a + b;
    return gcd(b % a, a);
}

fun factor(_x: Int): Int {
    var i = 2;
    var ans = 0;
    var x = _x;
    while (true) {
        if (i * i > x) break;
        while (x % i == 0) {
            x /= i;
            ans++;
        }
        i++;
    }
    if (x > 1) ans++;
    return ans
}

fun main() {
    var T = readInt();
    for (tc in 0..T - 1) {
        var(a, b, k) = readInts();
        var c = gcd(a, b);
        var lo = 0;
        if (a > c) lo++;
        if (b > c) lo++;
        var hi = factor(a) + factor(b);
        if (lo <= k && k <= hi) {
            if (a == b && k == 1) {
                println("NO")
            } else {
                println("YES");
            }
        } else {
            println("NO");
        }
    }
}