fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, s) = readLine()!!.split(' ').map { it.toLong() }
        var mn = (s + n - 1) / s
        var mx = s
        fun ok(lst: Long): Boolean {
            val unescaped = generateSequence(lst) { (it + 1) / 2 }.takeWhile { it > 1 }.toMutableList()
            if (unescaped.size < n) return (unescaped.sum() + (n - unescaped.size)) <= s
            return unescaped.slice(0 until n.toInt()).sum() <= s
        }
        if (ok(mx)) return@repeat println(mx)
        while (mn + 1 < mx){
            val m = (mn + mx) / 2
            if (ok(m)) mn = m else mx = m
        }
        println(mn)
    }
}