private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    val (n, m) = readInts()
    val s = Array(n) { IntArray(n) }
    val rsum = IntArray(n)
    val csum = IntArray(n)
    val (x, y) = readInts().map{ it - 1 }
    for(tt in 0 until m - 1) {
        val (i, j) = readInts().map { it - 1 }
        s[i][j]++
        rsum[i]++
        csum[j]++
    }
    var ans = 0
    for(i in 0 until n) if (i != x) for(j in 0 until n) if (j != y && i != j) {
        ans = maxOf(ans, rsum[i] + csum[j] - s[i][j])
    }
    println(ans + 1)
}

fun main() {
    val tt = 1
    repeat(tt) { solve() }
}