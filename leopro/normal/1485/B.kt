fun main() {
//    repeat(readLine()!!.toInt()) {
    val (n, q, k) = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val cnt = IntArray(n) { (if (it == a.lastIndex) k + 1 else a[it + 1]) - (if (it == 0) 0 else a[it - 1]) - 2 }
    val prefixSum = IntArray(n + 1)
    for (i in 0 until n) prefixSum[i + 1] = prefixSum[i] + cnt[i]

    repeat(q) {
        val (l, r) = readLine()!!.split(' ').map { it.toInt() - 1 }
        if (l == r) {
            return@repeat println(k - 1)
        }
        val inside = prefixSum[r] - prefixSum[l + 1]
        println(k - a[r - 1] - 1 + a[l + 1] - 1 - 1 + inside)
    }
//    }
}