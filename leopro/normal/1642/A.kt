import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val (x1, y1) = readLine()!!.split(' ').map { it.toInt() }
        val (x2, y2) = readLine()!!.split(' ').map { it.toInt() }
        val (x3, y3) = readLine()!!.split(' ').map { it.toInt() }
        if (y1 == y2 && y3 < y1) println(abs(x1 - x2))
        else if (y3 == y2 && y1 < y2) println(abs(x3 - x2))
        else if (y1 == y3 && y2 < y1) println(abs(x1 - x3))
        else println(0)
    }
}