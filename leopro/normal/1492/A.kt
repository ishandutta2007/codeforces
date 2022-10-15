fun main() {
    repeat(readInt()) {
        val (p, a, b, c) = readLongs()
        fun time(p: Long, t: Long): Long {
            return (p + t - 1) / t * t - p
        }
        val time = minOf(time(p, a), time(p, b), time(p, c))
        println(time)
    }
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()