fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val borders = List(n) { readLine()!!.split(' ').run { first().toInt() - k to last().toInt() - k } }
        println(borders.filter { (l, r) -> l <= 0 && r >= 0 }.map { (l, r) -> r + 1 }.maxOrNull() ?: 0)

    }
}