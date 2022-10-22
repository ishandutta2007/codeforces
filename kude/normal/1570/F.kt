private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    val (n, m) = readInts()
    val a = readMatrix(n)
    val ans = ArrayList<Pair<Int, Int>>()
    for(i in 0 until n - 1) {
        for(j in 0 until m - 1) {
            var ok = true
            for(x in i..i+1) for(y in j..j+1) if (a[x][y] == 0) ok = false
            if (ok) ans += Pair(i, j)
        }
    }
    for((i, j) in ans) for(x in i..i+1) for(y in j..j+1) a[x][y] = 0
    var ok = true
    for(i in 0 until n) for(j in 0 until m) if (a[i][j] == 1) ok = false
    if (!ok) {
        println(-1)
    } else {
        println(ans.size)
        for((i, j) in ans) println("${i + 1} ${j + 1}")
    }
}

fun main() {
   val tt = 1
   repeat(tt) { solve() }
}