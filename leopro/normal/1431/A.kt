fun main() {
    repeat(readInt()){
        val n = readInt()
        val a = readLongs().sortedDescending()
        var ans = 0L
        for (i in a.indices){
            ans = maxOf(ans, a[i] * (i + 1))
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