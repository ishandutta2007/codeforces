fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
        var powers = 0
        for (i in a.indices) {
            while (a[i] % 2 == 0L) {
                a[i] = a[i] / 2
                powers++
            }
        }
        val j = a.indices.maxByOrNull { a[it] }!!
        a[j] = a[j] * (1L shl powers)
        println(a.sumOf { it })
    }
}