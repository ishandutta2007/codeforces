fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!
        if (n.length == 2) return@repeat println(n.last())
        println(n.minOf { it })
    }
}