fun main() {
    repeat(readInt()) {
        val (n, u, v) = readInts()
        val a = readIntArray()
        val d = IntArray(n - 1)
        for (i in d.indices) d[i] = a[i + 1] - a[i]
        if (d.all { it == -1 || it == 0 || it == 1 }) {
            if (d.all { it == 0 }) println(v + minOf(u, v)) else {
                println(minOf(u, v))
            }
        } else {
            println(0)
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