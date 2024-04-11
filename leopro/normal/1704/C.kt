fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, _) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
        val lengths = ((1..a.lastIndex).map { a[it] - a[it - 1] } + listOf(a[0] - a.last() + n))
            .map { it - 1 }.filterNot { it == 0 }.sortedDescending().toIntArray()
        if (lengths.isEmpty()) return@repeat println(n)
        var ans = 0
        var cur = 0
        var res = 0
        for (i in lengths.indices) {
            val x = lengths[i]
            if (x - 2 * cur <= 0) break
            if (x - 2 * cur <= 2) {
                ans++
                cur++
            } else {
                ans += x - 2 * cur - 1
                cur += 2
            }
            val ones = run {
                var l = 0
                var r = lengths.size - i
                while (r - l > 1) {
                    val m = (l + r) / 2
                    if (lengths[i + m] - 2 * cur > m) l = m else r = m
                }
                l
            }
            res = maxOf(res, ans + ones)
        }
        println(n - res)
    }
}