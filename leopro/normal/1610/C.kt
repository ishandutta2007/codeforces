fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = IntArray(n)
        val b = IntArray(n)
        for (i in 0 until n) {
            val (x, y) = readLine()!!.split(' ').map { it.toInt() }
            a[i] = x
            b[i] = y
        }
        var l = 0
        var r = n + 1
        while (r - l > 1) {
            val m = (l + r) / 2
            var j = 0
            for (i in 0 until n) {
                if (a[i] + 1 + j >= m && b[i] >= j) ++j
            }
            if (j >= m) l = m else r = m
        }
        println(l)
    }
}