/*
    author:  Maksim1744
    created: 26.10.2020 12:07:43
*/

import kotlin.math.*;

fun test_case() {
    var (n, k, x, y) = readLine()!!.split(" ").map{ it.toInt() }
    var a = readLine()!!.split(" ").map{ it.toInt() }.toIntArray();
    a.sort();
    var sum: Long = 0;
    var ans: Long = 0;
    for (item in a) {
        sum += item;
        if (item > k) {
            ans += x;
        }
    }
    for (i in n-1 downTo 0) {
        if (sum <= n.toLong() * k) {
            if (a[i] > k) {
                ans = min(ans, x.toLong() * (n - 1 - i) + y);
            } else {
                ans = min(ans, x.toLong() * (n - 1 - i));
            }
        }
        sum -= a[i];
    }
    print("$ans\n");
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}