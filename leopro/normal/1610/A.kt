fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        if (n == 1 && m == 1) return@repeat println(0)
        if (n == 1 || m == 1) return@repeat println(1)
        println(2)
    }
}