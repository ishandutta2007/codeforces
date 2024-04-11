fun main() {
    repeat(readInt()) {
        val n = readInt()
        val a = readIntArray()
        val ord = IntArray(n)
        var last = 0
        for (i in ord.indices) {
            val diff = i - last
            val small = a.indices.minByOrNull { a[it] }!!
            if (a[small] > diff) {
                val big = a.indices.filter { a[it] != n + 1 }.maxByOrNull { a[it] }!!
                ord[i] = big
                a[big] = n + 1
            } else {
                ord[i] = small
                a[small] = n + 1
                last = i
            }
        }
        println(ord.joinToString(" ") { (it + 1).toString() })
    }
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()