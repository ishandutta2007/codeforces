fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val c = List(n) { readLine()!!.split(' ').map { it.toLong() }.toLongArray() }
        val count = c.indices.map { c[it].mapIndexed { index, value -> index * value }.sumOf { it } }
        val k = count.indices.maxByOrNull { count[it] }!!
        val notK = if (k == 0) k + 1 else k - 1
        println("${k.plus(1)} ${count[k] - count[notK]}")
    }
}