/*
    author:  Maksim1744
    created: 12.11.2020 17:55:09
*/

import kotlin.collections.*;

fun test_case() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{ it.toInt() }
    var s = MutableList(n) { Pair(0, 0) }
    for (i in 0 until n) {
        s[i] = Pair(a[i], i + 1)
    }
    s.sortBy({ it.first * 1000 + it.second })
    var last = 0
    var used = MutableList(n) { false }
    var ord = MutableList(n) {-1}
    for (i in 0 until n) {
        if (last + s[i].first >= n) {
            var ind = 0;
            for (j in i until n) {
                while (used[ind]) {
                    ind += 1;
                }
                used[ind] = true;
                ord[ind] = s[j].second;
            }
            for (x in ord) {
                print("$x ");
            }
            println()
            return;
        }
        last += s[i].first;
        used[last] = true;
        ord[last] = s[i].second;
    }
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}