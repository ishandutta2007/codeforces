fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.sorted()
    val b = readLine()!!.split(' ').map { it.toInt() }.sorted()
    val prefixMin = IntArray(n + 1)
    prefixMin[0] = b[0] - a[0]
    for (i in 1 until n) prefixMin[i] = maxOf(b[i] - a[i], prefixMin[i - 1])
    val suffixMin = IntArray(n + 1)
    suffixMin[n] = b[n] - a[n - 1]
    for (i in n - 1 downTo 1) suffixMin[i] = maxOf(b[i] - a[i - 1], suffixMin[i + 1])
    readLine()
    val ans = mutableListOf<Int>()
    for (c in readLine()!!.split(' ').map { it.toInt() }) {
        var l = -1
        var r = n
        while (r - l > 1) {
            val m = (l + r) / 2
            if (c < a[m]) r = m else l = m
        }
        ans.add(
            maxOf(
                (if (l == -1) Int.MIN_VALUE else prefixMin[l]),
                b[l + 1] - c,
                (if (l == n - 1) Int.MIN_VALUE else suffixMin[l + 2])
            )
        )
    }
    println(ans.joinToString(" "))
}