fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, y, x) = readLine()!!.split(' ').map { it.toInt() }.sortedDescending()
        fun time(x: Int, l: Int, r: Int) = minOf(x - l, r - x) + r - l
        var ans = Int.MAX_VALUE
        for (m in x until y) {
            ans = minOf(ans, maxOf(time(x, 1, m), time(y, m + 1, n)))
        }
        println(ans)
    }
}