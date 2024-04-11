fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        var ans = 0L
        for (l in 0 until a.size - 1) {
            val r = l + 1
            ans = maxOf(ans, a[l] * 1L * a[r])
        }
        println(ans)
    }
}