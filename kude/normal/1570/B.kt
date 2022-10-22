private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val tt = 1
    repeat(tt) {
        var a1 = readInt()
        var a2 = readInt()
        var k1 = readInt()
        var k2 = readInt()
        if (k1 > k2) {
            val temp = k1
            k1 = k2
            k2 = temp
            val temp2 = a1
            a1 = a2
            a2 = temp2
        }
        val n = readInt()
        val mn = maxOf(0, n - (k1 - 1) * a1 - (k2 - 1) * a2)
        var mx = 0
        var rest = n
        val c1 = minOf(a1, rest / k1)
        mx += c1
        rest -= c1 * k1
        val c2 = minOf(a2, rest / k2)
        mx += c2
        rest -= c2 * k2
        println("$mn $mx")
    }
}