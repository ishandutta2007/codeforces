fun main() {
    repeat(readInt()) {
        val s = readLine()!!
        var ans = 0
        var prev = 0
        for (i in s.indices) {
            if (prev > 0 && s[i] == 'B') {
                prev--
                ans++
            } else {
                prev++
            }
        }
        println(s.length - 2 * ans)
    }
}

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()