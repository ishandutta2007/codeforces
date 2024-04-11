fun main() {
    val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map { it.toInt() }.reversed().toIntArray()
    var idx = 1
    var size = 0
    for (i in a.indices) {
        if (idx == m && size + a[i] > k) return println(i)
        if (size + a[i] <= k) size += a[i] else size = a[i].also { idx++ }
    }
    println(n)
}