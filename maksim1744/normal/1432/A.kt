/*
    author:  Maksim1744
    created: 05.11.2020 19:46:23
*/

fun test_case() {
    var (a, b) = readLine()!!.split(" ").map{ it.toInt() }
    println(a + b)
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}