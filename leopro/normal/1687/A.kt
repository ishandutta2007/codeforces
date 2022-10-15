fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        if (n > k) {
            val pref = LongArray(n + 1)
            for (i in a.indices) pref[i + 1] = pref[i] + a[i]
            var sum = 0L
            for (i in k..a.size) {
                sum = maxOf(sum, pref[i] - pref[i - k])
            }
            sum += k * 1L * (k - 1) / 2
            println(sum)
        } else {
            for (i in a.indices) a[i] += k - 1
            var sum = 0L
            for (x in a) sum += x
            println(sum - n * 1L * (n - 1) / 2)
        }
    }
}