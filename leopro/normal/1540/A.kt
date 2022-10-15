fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted()
        var ans = a.last().toLong()
        var cur = 0L
        for (i in 1 until n) {
            cur += a[i - 1]
            ans -= i * 1L * a[i] - cur
        }
        println(ans)
    }
}