fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val row = readLine()!!
        val next = IntArray(n) { Int.MAX_VALUE }
        val prev = IntArray(n) { Int.MIN_VALUE }
        for (i in (0 until n).reversed()) {
            if (row[i] == '1') next[i] = i else next[i] = if (i + 1 == n) Int.MAX_VALUE else next[i + 1]
        }
        for (i in 0 until n) {
            if (row[i] == '1') prev[i] = i else prev[i] = if (i == 0) Int.MIN_VALUE else prev[i - 1]
        }
        for (i in 0 until n){
            print(if ((i + 0L - prev[i] <= m || next[i] + 0L - i <= m) && (row[i] == '1' || i + 0L - prev[i] != next[i] + 0L - i)) '1' else '0')
        }
        println()
    }
}