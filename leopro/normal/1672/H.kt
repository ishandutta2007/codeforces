// The editorial for the problem https://codeforces.com/problemset/problem/1329/D was used

fun main() {
    val (n, q) = readLine()!!.split(' ').map { it.toInt() }
    val s = readLine()!!
    val indices = List(2) { mutableListOf<Int>() }
    for (i in 1 until s.length) {
        if (s[i] == s[i - 1]) {
            indices[s[i] - '0'].add(i)
        }
    }
    val ind = List(2) { indices[it].toIntArray() }
    val ans = IntArray(q)
    repeat(q) {
        val (l, r) = readLine()!!.split(' ').map { it.toInt() }
        val c0 = countLess(ind[0], r) - countLess(ind[0], l)
        val c1 = countLess(ind[1], r) - countLess(ind[1], l)
        ans[it] = maxOf((c0 + c1 + 1) / 2, maxOf(c0, c1)) + 1
    }
    println(ans.joinToString("\n"))
}

fun countLess(a: IntArray, x: Int): Int {
    var l = 0
    var r = a.size + 1
    while (r - l > 1) {
        val m = (l + r) / 2
        if (a[m - 1] < x) l = m else r = m
    }
    return l
}