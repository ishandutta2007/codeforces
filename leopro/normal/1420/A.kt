fun main() {
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        val a = readInts().toIntArray()
        val b = a.sortedBy { -it }.toIntArray()
        val same = (1 until n).find { b[it] == b[it - 1] }
        println(if (a.contentEquals(b) && same == null) "NO" else "YES")
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readLongs() = readLine()!!.split(' ').map { it.toLong() }