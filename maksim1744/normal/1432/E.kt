/*
    author:  Maksim1744
    created: 05.11.2020 20:04:36
*/

import kotlin.math.*

fun test_case() {
    var ss = readLine()!!.split(" ")
    var n = ss[0].toInt()
    var k = ss[1].toLong()
    var s = readLine()!!.toCharArray()
    var last = 0
    for (i in 0 until n) {
        if (s[i] == '1') {
            continue
        }
        var mv = i - last
        if (mv > k) {
            mv = k.toInt()
        }
        var tmp = s[i]
        s[i] = s[i - mv]
        s[i - mv] = tmp
        k -= mv.toLong()
        last += 1
    }
    println(s)
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}