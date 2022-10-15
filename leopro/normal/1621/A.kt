fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        if (2 * k - 1 > n) return@repeat println(-1)
        println(List(n) { i -> CharArray(n) { j -> if (i == j && i in (0 until 2 * k step 2)) 'R' else '.' }.joinToString("") }.joinToString("\n"))
    }
}