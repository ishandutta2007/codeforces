/*
    author:  Maksim1744
    created: 05.11.2020 19:54:18
*/

fun test_case() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{ it.toInt() }
    var sm = 0
    for (k in a) {
        sm += k
    }
    println((sm + n - 1) / n)
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}