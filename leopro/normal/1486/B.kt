fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val points = MutableList(n) { readLine()!!.split(' ').map { it.toInt() }.let { it[0] to it[1] } }
        points.sortBy { it.first }
        val leftX = points[(n + 1) / 2 - 1].first
        val rightX = points[n / 2].first
        points.sortBy { it.second }
        val leftY = points[(n + 1) / 2 - 1].second
        val rightY = points[n / 2].second
        println((rightX - leftX + 1) *1L *  (rightY - leftY + 1))
    }
}