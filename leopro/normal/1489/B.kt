fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, a, b) = readLine()!!.split(' ').map { it.toLong() }
        println(n % 2 * a + n / 2 * minOf(2 * a, b))
    }
}