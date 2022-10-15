fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        var ans = Long.MIN_VALUE
        for (i in a.indices.reversed()) {
            for (j in i - 1 downTo 0) {
                if (ans >= (i + 1) *1L* (j + 1)) break
                ans = maxOf(ans, (i + 1) * 1L * (j + 1) - k * 1L * (a[i] or a[j]))
            }
        }
        println(ans)
    }
}