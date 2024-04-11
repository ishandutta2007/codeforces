import kotlin.math.*;

fun test_case() {
    var (n, k1, k2) = readLine()!!.split(" ").map{ it.toInt() }
    var c = IntArray(n + 1);
    var s = readLine()!!;
    for (i in 0 until n) {
        if (s[i] == '0') continue
        c[i + 1] = min(k1, k2 - c[i]);
    }
    var res = 0;
    for (i in 1..n) {
        res += c[i];
    }
    print("$res\n");
}

fun main() {
    val t = readLine()!!.toInt();
    for (test in 1..t) {
        test_case();
    }
}