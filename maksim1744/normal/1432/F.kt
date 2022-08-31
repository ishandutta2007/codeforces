/*
    author:  Maksim1744
    created: 05.11.2020 20:15:22
*/

import kotlin.math.*
import java.util.Arrays

fun main() {
    var (n, m, d) = readLine()!!.split(" ").map{ it.toInt() }
    var c = readLine()!!.split(" ").map{ it.toInt() }
    var pos = Array(m){0}
    var cur_pos = 0
    for (i in 0 until m) {
        cur_pos = cur_pos + d
        pos[i] = cur_pos
        cur_pos += c[i] - 1
    }
    // println(Arrays.toString(pos))
    if (cur_pos + d < n + 1) {
        println("NO")
        return
    }
    var last = n + 1
    for (i in m - 1 downTo 0) {
        pos[i] = min(pos[i], last - c[i])
        last = pos[i]
    }
    var res = Array(n){0}
    for (i in 0 until m) {
        for (j in pos[i] until pos[i] + c[i]) {
            res[j - 1] = i + 1;
        }
    }
    println("YES")
    for (k in res) {
        print("$k ")
    }
    println()
}