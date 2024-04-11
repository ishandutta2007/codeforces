fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val pts = List(m) { readLine()!!.split(' ').map { it.toInt() }.run { Point(first(), last()) } }.withIndex()
            .sortedBy { it.value.w }.take(2 * n).sortedBy { it.value.x }
        println(pts.sumOf { it.value.w })
        val ans = List(n) { mutableListOf<Int>() }
        for (i in 0 until n) {
            ans[i].add(pts[i].index + 1)
            ans[i].add(pts[pts.lastIndex - i].index + 1)
        }
        println(ans.joinToString("\n") { it.joinToString(" ") })
    }
}

data class Point(val x: Int, val w: Int)