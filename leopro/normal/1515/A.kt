fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, x) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
        if (a.sum() == x) return@repeat println("NO")
        var s = 0
        for (i in 0 until a.size - 1) {
            s += a[i]
            if (x == s) {
                a[i + 1] = a[i].also { a[i] = a[i + 1] }
                break
            }
        }
        println("YES")
        println(a.joinToString(" "))
    }
}