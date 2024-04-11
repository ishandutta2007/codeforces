fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val d = LongArray(n) { 0L }
        d[0] = a[0].toLong()
        for (i in 1 until n) {
            d[i] = a[i] - d[i - 1]
        }
        if (d.all { it >= 0 } && d.last() == 0L) return@repeat println("YES")
        if (d.any { it < 0 } && d.last() == 0L) return@repeat println("NO")
        val suffixMin = LongArray(d.size)
        suffixMin[d.size - 1] = d[d.size - 1]
        suffixMin[d.size - 2] = d[d.size - 2]
        for (i in (0 until d.size - 2).reversed()) {
            suffixMin[i] = minOf(suffixMin[i + 2], d[i])
        }
        for (i in 0..((0..n - 2).find { d[it] < 0 } ?: n - 2)) {
            if (2L * (a[i + 1] - a[i]) == d.last() * if ((n - i) % 2 == 1) -1 else 1) {
                if (suffixMin[i + 1] - 2 * (a[i + 1] - a[i]) >= 0) {
                    if (i + 2 == n || suffixMin[i + 2] + 2 * (a[i + 1] - a[i]) >= 0) {
                        if (a[i + 1] - (if (i == 0) 0 else d[i - 1]) >= 0) return@repeat println("YES")
                    }
                }
            }
        }
        println("NO")
    }
}