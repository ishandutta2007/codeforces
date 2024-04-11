/*
    author:  Maksim1744
    created: 05.11.2020 19:57:28
*/

fun test_case() {
    var (n, a, b) = readLine()!!.split(" ").map{ it.toInt() }
    var s = StringBuilder()
    var c = 0
    for (i in 0 until n) {
        s.append((c + 'a'.toInt()).toChar())
        c = (c + 1) % b
    }
    println(s.toString())
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}