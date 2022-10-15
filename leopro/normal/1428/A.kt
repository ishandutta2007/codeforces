fun main() {
    repeat(readInt()){
        val (x1, y1, x2, y2) = readInts()
        println(kotlin.math.abs(x1 - x2) + kotlin.math.abs(y1 - y2) + if (x1 != x2 && y1 != y2) 2 else 0)
    }
}

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()