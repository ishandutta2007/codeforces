fun main() {
    repeat(readInt()) {
        val (n, k) = readInts()
        val p = readIntArray()
        var ans = 0
        for (buy in 0..n) {
            val free = buy / k
            var cur = 0
            for (f in n - buy until n - buy + free) {
                cur += p[f]
            }
            ans = maxOf(ans, cur)
        }
        println(ans)
    }
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()