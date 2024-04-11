const val INF = 1e12.toLong()

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }
        val offers = List(n) { mutableListOf<Offer>() }
        repeat(m) {
            val (e, t, p) = readLine()!!.split(' ').map { it.toInt() }
            val offer = Offer(t, p, it + 1)
            offers[e - 1].add(offer)
        }
        val order = mutableListOf<Offer>()
        var cur = 0L
        for (i in 0 until n) {
            val time = minTimeFor(offers[i], 100, order)
            cur += time
            if (cur > a[i]) return@repeat println(-1)
        }
        println(order.size)
        println(order.map { it.i }.joinToString(" "))
    }
}

fun minTimeFor(offers: List<Offer>, minP: Int, order: MutableList<Offer>): Long {
    val dp = List(offers.size + 1) { LongArray(2 * minP + 1) { INF } }
    dp[0][0] = 0
    for (i in offers.indices) {
        val (t, p, _) = offers[i]
        for (p0 in dp[i + 1].indices) {
            dp[i + 1][p0] = dp[i][p0]
            if (p0 - p >= 0) {
                dp[i + 1][p0] = minOf(dp[i + 1][p0], dp[i][p0 - p] + t)
            }
        }
    }
    fun restore(i: Int, curP: Int) {
        if (curP == 0) return
        if (dp[i - 1][curP] == dp[i][curP]) return restore(i - 1, curP)
        restore(i - 1, curP - offers[i - 1].p)
        order.add(offers[i - 1])
    }

    val ans = dp[offers.size].slice(minP..2 * minP).minOf { it }
    if (ans < INF) restore(offers.size, (minP..2 * minP).minByOrNull { dp[offers.size][it] }!!)
    return ans
}

data class Offer(val t: Int, val p: Int, val i: Int)