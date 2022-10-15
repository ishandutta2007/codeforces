fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        var min = n - 1
        for (i in a.indices) {
            for (j in a.indices) {
                if (i == j) continue
                var cnt = 0
                for (k in a.indices) {
                    if ((a[i] - a[j]) * (i - k) != (a[i] - a[k]) * (i - j)) cnt++
                }
                min = minOf(min, cnt)
            }
        }
        println(min)
    }
}