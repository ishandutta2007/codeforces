/*
    author:  Maksim1744
    created: 12.11.2020 18:08:58
*/

import kotlin.math.*;

fun test_case() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{ it.toInt() }
    var b = readLine()!!.split(" ").map{ it.toInt() }
    // var pbest = MutableList(n) {-1}
    var curb = -1;
    var ans = -1;
    for (s in 0 until n) {
        var cur = 100000000;
        for (i in 0 until n) {
            cur = min(cur, abs(a[i] - b[(i + s) % n]))
        }
        if (cur > ans) {
            ans = cur;
            curb = s;
        }
    }
    for (i in 0 until n) {
        var x = (i + curb) % n + 1;
        print("$x ")
    }
    println()
    // while (r - l > 1) {
    //     var c = (l + r) / 2;
    //     var ind = 0;
    //     var with = MutableList(n) { -1 };
    //     var ia = 0;
    //     while (ia < n) {
    //         while (ind < n && b[ind] < a[ia] + c) {
    //             ind += 1;
    //         }
    //         if (ind == n) {
    //             break;
    //         }
    //         with[ind] = ia
    //         ind += 1
    //         ia += 1;
    //     }
    //     ind = 0
    //     var ok = true
    //     while (ia < n) {
    //         while (with[ind] != -1) {
    //             ind += 1;
    //         }
    //         if (b[ind] > a[ia] - c) {
    //             ok = false;
    //             break;
    //         }
    //         with[ind] = ia;
    //         ia += 1
    //     }
    //     println("$with, $c, $ok")
    //     if (ok) {
    //         l = c;
    //         for (i in 0 until n) {
    //             pbest[with[i]] = i;
    //         }
    //     } else {
    //         r = c;
    //     }
    // }
    // for (x in pbest) {
    //     var y = x + 1
    //     print("$y ");
    // }
    // println()
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}