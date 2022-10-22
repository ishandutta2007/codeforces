private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    val n = readInt()
    var mx = 1001001001
    var mn = 0
    for(xx in 0 until n) {
        val (s, t, r_) = readStrings()
        val r = r_.toInt()
        var i = s.length - 1
        var j = t.length - 1
        var c = 0
        while(i >= 0 && j >= 0) {
            if (s[i] == t[j]) {
                c++
            } else break
            i--
            j--
        }
        if (r == 0) {
            mn = maxOf(mn, c + 1)
        } else {
            mx = minOf(mx, c)
        }
    }
    if (mn > mx) {
        println(0)
        return
    }
    println("${mx - mn + 1}\n" + Array(mx - mn + 1) {it + mn}.joinToString(" "))
}

fun main() {
    val tt = readInt()
    repeat(tt) { solve() }
}