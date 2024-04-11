private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun solve() {
    val s = readLn()
    var nxt = -1
    var seen = false
    var ans = 0
    for((i, c) in s.withIndex()) {
        if (c == '0') continue
        if (!seen) {
            seen = true
        } else {
            ans += i - nxt
        }
        nxt = i + 1
    }
    println(ans)
}

fun main() {
    val tt = readInt()
    repeat(tt) { solve() }
}