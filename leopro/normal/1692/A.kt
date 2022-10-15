fun main() {
    repeat(readLine()!!.toInt()) {
        val p = readLine()!!.split(' ').map { it.toInt() }
        println(p.count { it > p.first() })
    }
}