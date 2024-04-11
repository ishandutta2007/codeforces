fun main() {
    repeat(readInt()) {
        val (u, v) = readInts()
        val s = (u + (1 shl 30)).toString(2).reversed()
        val t = (v + (1 shl 30)).toString(2).reversed()
        if (v < u) return@repeat println("NO")
//        if (s.count { it == '1' } != t.count { it == '1' }) return@repeat println("NO")
        var x = 0
        for (i in s.indices) {
            if (s[i] == t[i]) continue
            if (s[i] == '1') {
                x++
            } else {
                if (x == 0) return@repeat println("NO")
                x--
            }
        }
        println("YES")
    }
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()