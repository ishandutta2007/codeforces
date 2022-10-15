fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        if (m < n) return@repeat println(0)
        var ans = 0
        fun ok(mask: Int, i: Int): Boolean {
            return (n xor mask) or ((1 shl i) - 1) > m
        }
        for (bit in 31 downTo 0) {
            if (!ok(ans, bit)) ans = ans or (1 shl bit)
        }
        println(ans)
    }
}