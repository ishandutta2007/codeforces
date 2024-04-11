fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val h = readLine()!!.split(' ').map { it.toInt() }.toIntArray() + intArrayOf(Int.MIN_VALUE, Int.MAX_VALUE)
        fun IntArray.pit(): Int {
            for (i in 0 until this.size - 1) if (this[i] < this[i + 1]) return i
            return -1
        }

        var cur = 0L
        while (true) {
            val lst = h.pit()
            if (lst == n) return@repeat println(-1)
            val fst = ((lst - 1 downTo 0).find { h[it] != h[it + 1] } ?: -1) + 1
            val mn = (if (fst == 0) h[lst + 1] else minOf(h[lst + 1], h[fst - 1])) - h[fst]
            if (cur + mn * (lst - fst + 1L) >= k) return@repeat println(lst + 1 - (k - cur - 1) % (lst - fst + 1))
            for (i in fst..lst) h[i] += mn
            cur += mn * (lst - fst + 1L)
        }
    }
}