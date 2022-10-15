fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val bigDowns = BooleanArray(n - 1) { i -> a[i] >= 2 * a[i + 1] }
        val p = IntArray(n)
        for (i in bigDowns.indices) p[i + 1] = p[i] + if (bigDowns[i]) 1 else 0
        var ans = 0
        for (i in k until n) {
            if (p[i] == p[i - k]) ans++
        }
        println(ans)
    }
}