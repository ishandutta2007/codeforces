fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        for (i in a.indices) a[i] += i
        println(a.sorted().slice(0 until n - k).mapIndexed { index, value -> value - index }.fold(0L) { a, b -> a + b })
    }
}