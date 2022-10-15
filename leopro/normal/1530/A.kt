fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!
        println(n.maxOf { it })
    }
}