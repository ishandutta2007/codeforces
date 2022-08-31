/*
    author:  Maksim1744
    created: 05.11.2020 19:49:27
*/

import kotlin.math.*

fun test_case() {
    var n = readLine()!!.toInt()
    var mn = n / 2 + 1
    var mx = n - 1
    println(max(0, mx - mn + 1))
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}