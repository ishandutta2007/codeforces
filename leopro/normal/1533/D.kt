fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val s = List(n) { readLine()!! }.groupBy { it }
    repeat(readLine()!!.toInt()) {
        val t = readLine()!!
        println(t.indices.map { t.take(it) + t.drop(it + 1) }.distinct().sumOf { s[it]?.size ?: 0 })
    }
}