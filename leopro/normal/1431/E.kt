import kotlin.math.abs

fun main() {
    repeat(readInt()) {
        val n = readInt()
        val a = readIntArray()
        val b = readIntArray()
        val c = b + b
        var ans = 0
        for (shift in 0 until n) {
            var cur = 1_000_000
            for (i in a.indices) cur = minOf(cur, abs(a[i] - c[i + shift]))
            ans = maxOf(ans, cur)
        }
        for (shift in 0 until n) {
            var cur = 1_000_000
            for (i in a.indices) cur = minOf(cur, abs(a[i] - c[i + shift]))
            if (ans == cur) {
                println(IntArray(n) { (it + shift) % n + 1}.joinToString(" "))
                return@repeat
            }
        }
    }
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()