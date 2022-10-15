fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = List(n) { readLine()!!.split(' ').map { it.toInt() }.toIntArray() }
        val indices = BooleanArray(m)
        for (i in 0 until n) {
            for ((j, x) in a[i].sorted().withIndex()) {
                if (x != a[i][j]) indices[j] = true
            }
        }
        val count = indices.count { it }
        if (count == 0) return@repeat println("1 1")
        if (count != 2) return@repeat println(-1)
        val i = indices.indices.find { indices[it] }!!
        val j = indices.indices.findLast { indices[it] }!!
        for (k in 0 until n) {
            a[k][i] = a[k][j].also { a[k][j] = a[k][i] }
            val b = a[k].sorted()
            if (b.indices.any { b[it] != a[k][it] }) return@repeat println(-1)
        }
        println("${i.plus(1)} ${j.plus(1)}")
    }
}