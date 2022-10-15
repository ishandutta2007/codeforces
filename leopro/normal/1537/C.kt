import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val h = readLine()!!.split(' ').map { it.toInt() }.sorted()
        val d = (1 until n).minOf { h[it] - h[it - 1] }
        if (h.last() - h.first() == d) return@repeat println(h.joinToString(" "))
        val i = (1 until n).minByOrNull { h[it] - h[it - 1] }!!
        val ans = h.slice(i until h.size) + h.slice(0 until i)
        println(ans.joinToString(" "))
    }
}