fun main() {
    repeat(1) {
        readLine()
        val s = readString()
        val t = readString()
        val begin = IntArray(t.length)
        val end = IntArray(t.length)
        for (i in t.indices) {
            var pos = (if (i == 0) -1 else begin[i - 1])
            do {
                pos++
            } while (s[pos] != t[i])
            begin[i] = pos
        }
        for (i in t.indices.reversed()) {
            var pos = (if (i == t.lastIndex) s.length else end[i + 1])
            do {
                pos--
            } while (s[pos] != t[i])
            end[i] = pos
        }
        var ans = 0
        for (i in 1 until t.length){
            ans = maxOf(ans, end[i] - begin[i - 1])
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