fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        println(List(n) { i -> IntArray(m) { j -> (i / 2 + j / 2) % 2 xor (i + j) % 2 } }.joinToString("\n") { it.joinToString(" ") })

    }
}