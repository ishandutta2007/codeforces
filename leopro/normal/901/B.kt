fun restore(x: IntArray, y: IntArray, a: IntArray, b: IntArray, n: Int) {
    if (n == 0) {
        for (i in x.indices) a[i] = x[i]
        for (i in y.indices) b[i] = y[i]
        return
    }
    val z = IntArray(x.size + 1)
    for (i in y.indices) z[i + 2] = y[i]
    for (i in x.indices) z[i + 1] += x[i]
    for (i in x.indices) z[i] += x[i]
    for (i in z.indices) z[i] -= (z[i] / 3) * 3
    for (i in z.indices) while (z[i] > 1) z[i] -= 3
    for (i in z.indices) while (z[i] < -1) z[i] += 3
    restore(z, x, a, b, n - 1)

}

fun main() {
    val n = readLine()!!.toInt()
    val x = IntArray(2) { 1 }
    val y = IntArray(1) { 1 }
    val a = IntArray(n + 1)
    val b = IntArray(n)
    restore(x, y,a,b, n - 1)
    println(
        "${a.size - 1}\n${a.reversed().joinToString(" ") { it.toString() }}\n" +
                "${b.size - 1}\n${b.reversed().joinToString(" ") { it.toString() }}"
    )
}