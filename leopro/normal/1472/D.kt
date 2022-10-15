fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.sortedDescending().toIntArray()
        val sumAlice = (0 until n step 2).filter { a[it] % 2 == 0 }.fold(0L) { acc, i -> acc + a[i] }
        val sumBob = (1 until n step 2).filter { a[it] % 2 == 1 }.fold(0L) { acc, i -> acc + a[i] }
        println(
            when (sumAlice - sumBob) {
                0L -> "Tie"
                in 1 until Long.MAX_VALUE -> "Alice"
                else -> "Bob"
            }
        )
    }
}