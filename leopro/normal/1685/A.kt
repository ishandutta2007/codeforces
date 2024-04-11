fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted()
        if (n % 2 == 1) return@repeat println("NO")
        val b = mutableListOf<Int>()
        for (i in 0 until n / 2) {
            b.add(a[i])
            b.add(a[i + n / 2])
        }
        val c = b + b + b
        for (j in n until 2 * n) {
            val ok1 = c[j - 1] < c[j] && c[j + 1] < c[j]
            val ok2 = c[j - 1] > c[j] && c[j + 1] > c[j]
            if (!ok1 && !ok2) return@repeat println("NO")
        }
        println("YES")
        println(b.joinToString(" "))
    }
}