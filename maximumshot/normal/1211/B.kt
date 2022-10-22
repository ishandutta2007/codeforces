
import kotlin.math.max

fun main() {
    val n: Int = readLine()!!.toInt()
    val a: IntArray = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    var minPath = 0L
    for ((i, x) in a.withIndex()) {
        if (x == 0) {
            continue
        }
        val need = i + max(0, x - 1).toLong() * n + 1
        if (minPath < need) {
            minPath = need
        }
    }
    println(minPath)
}