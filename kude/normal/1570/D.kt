private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun f(n: Int): Int {
    var n = n + 1
    while(n % 10 == 0) n /= 10
    return n
}

private fun solve() {
    var n = readInt()
    val s = mutableSetOf<Int>(n)
    while(n != 1) {
        n = f(n)
        s += n
    }
    n = f(n)
    s += n
    while(n != 1) {
        n = f(n)
        s += n
    }
    print(s.size)
}

fun main() {
    val tt = 1
    repeat(tt) { solve() }
}