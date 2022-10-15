fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, h) = readLine()!!.split(' ').map { it.toLong() }
        val a = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
        var l = 0L
        var r = h
        while (r - l > 1) {
            val m = (l + r) / 2
            var sum = 0L
            for ((x, y) in a.toList().zipWithNext()) {
                sum += minOf(y - x, m)
            }
            sum += m
            if (sum >= h) r = m else l = m
        }
        println(r)
    }
}