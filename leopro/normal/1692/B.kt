fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val d = a.distinct().size
        println(if (d % 2 == n % 2) d else d - 1)
    }
}