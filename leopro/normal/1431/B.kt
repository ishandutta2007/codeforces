fun main() {
    repeat(readInt()){
        val s = readString()
        var ans = 0
        var cnt = 0
        for (i in s.indices){
            if (s[i] == 'w'){
                ans += cnt / 2
                ans++
                cnt = 0
            } else {
                cnt++
            }
        }
        println(ans + cnt / 2)
    }
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()