import java.lang.Math.abs

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val N = readLine()!!.toInt()
        val A = readLine()!!.split(" ").map { it.toLong() }
        val B = readLine()!!.split(" ").map { it.toLong() }
        val SA = A.mapIndexed { i, v -> v to i }.sortedBy { it.first }
        val SB = B.mapIndexed { i, v -> v to i }.sortedBy { it.first }
        val ans = (0..N).map {
            val ff = SA.take(it).zip(SB.takeLast(it))
            val gg = SA.drop(it).zip(SB.dropLast(it))
            val hh = ff + gg
            hh
        }.maxBy {
            val s = it.map { abs(it.first.first - it.second.first) }.min()!!
            s
        }
        println(ans!!.sortedBy { it.first.second }.joinToString(" ") { "${it.second.second + 1 }" })
    }
}