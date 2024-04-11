fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, a, b) = readInts()
        println((0 until n).map { it % b }.map { 'a' + it }.joinToString(""))
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }