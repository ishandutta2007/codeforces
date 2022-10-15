fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b, c) = readLine()!!.split(' ').map { it.toInt() }
        val x = a + b * 1e9.toLong()
        val y = b
        val z = c
        println("$x $y $z")
    }
}