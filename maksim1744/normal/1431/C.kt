/*
    author:  Maksim1744
    created: 12.11.2020 17:46:10
*/

import kotlin.math.max;

fun test_case() {
    var (n, k) = readLine()!!.split(" ").map{ it.toInt() }
    var a = readLine()!!.split(" ").map{ it.toInt() }.toIntArray()
    var s = a;
    for (i in 1 until n) {
        s[i] += s[i - 1];
    }
    var ans = 0
    for (l in 0 until n) {
        var r = n - 1;
        var x = (r - l + 1)
        var free = x / k;
        if (free != 0) {
            var rf = l + free - 1;
            var cur = s[rf];
            if (l != 0) {
                cur -= s[l - 1];
            }
            ans = max(ans, cur);
        }
    }
    println(ans);
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}