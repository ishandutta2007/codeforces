fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        val p = readLine()!!.split(' ').map { it.toInt() - 1 }.toIntArray()
        val used = BooleanArray(n)
        var ans = 1L
        for (i in 0 until n) {
            if (used[i]) continue
            val row = mutableListOf<Char>()
            var j = i
            do {
                used[j] = true
                row.add(s[j])
                j = p[j]
            } while (j != i)
            var period = row.size
            for (p in 1 until row.size) {
                if (row.size % p != 0) continue
                if ((0 until row.size - p).all { row[it] == row[it + p] }) {
                    period = p
                    break
                }
            }
            ans *= period / gcd(ans, period.toLong())
        }
        println(ans)
    }
}

data class Cell(val i: Int, val j: Int)

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)