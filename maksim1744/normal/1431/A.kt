/*
    author:  Maksim1744
    created: 12.11.2020 17:35:48
*/

import kotlin.math.max;
import kotlin.collections.sort;

fun test_case() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{ it.toLong() }.sorted()
    var ans: Long = 0
    for (i in 0 until n) {
        ans = max(ans, a[i] * (n - i).toLong())
    }
    println(ans)
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}