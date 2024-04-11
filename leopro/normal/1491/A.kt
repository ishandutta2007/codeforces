fun main() {
    val (n, q) = readInts()
    val a = readIntArray()
    var ones = a.count { it == 1 }
    repeat(q) {
        val (t, x) = readInts()
        if (t == 1) {
            a[x - 1] = 1 - a[x - 1]
            if (a[x - 1] == 1) ones++ else ones--
        } else {
            println(if (ones >= x) 1 else 0)
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