fun main() {
    repeat(readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() }
        println((1 until 100_000).takeWhile { r -> r * (r + 2) <= x && r + 1 <= y }.map { r ->
            minOf(y - r, x / r - r - 1).toLong()
        }.fold(0L) { a, b -> a + b })
    }
}