fun main() {
    repeat(readInt()){
        val x = readLine()!!
        val ans = 10 * (x[0] - '1') + x.length * (x.length + 1) / 2
        println(ans)
    }
}

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()