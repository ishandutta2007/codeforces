const val INF = Int.MAX_VALUE.toLong()

fun main() {
    val ans = mutableListOf<Long>()
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
        val tmp = List(m) {
            readLine()!!.split(' ').map { it.toInt() }.run { Segment(first(), last()) }
        }.sortedWith(compareBy<Segment> { it.l }.thenBy { it.r })
        val s = mutableListOf<Segment>()
        var idx = -1
        for (v in tmp) {
            while (idx + 1 < a.size && a[idx + 1] < v.l) ++idx
            if (idx + 1 < a.size && a[idx + 1] <= v.r) continue
            while (s.isNotEmpty() && v.r <= s.last().r) s.removeLast()
            s.add(v)
        }
        val left = IntArray(s.size)
        idx = -1
        for (j in s.indices) {
            while (idx + 1 < a.size && a[idx + 1] < s[j].r) ++idx
            left[j] = idx
        }
        val dp = LongArray(s.size + 1) { INF }
        idx = -1
        var bestSoFar = if (s.isEmpty() || s[0].l > a[0]) 0 else INF
        dp[0] = 0
        for (i in a.indices) {
            while (idx + 1 < s.size && s[idx + 1].r < a[i]) ++idx
            var singleCost = bestSoFar
            var doubleCost = bestSoFar
            for (j in idx downTo 0) {
                if (left[j] != i - 1) break
                val dpValue = dp[j]
                singleCost = minOf(singleCost, a[i] - s[j].r + dpValue)
                doubleCost = minOf(doubleCost, 2L * (a[i] - s[j].r) + dpValue)
            }

            if (idx + 1 == s.size || left[idx + 1] != i) {
                bestSoFar = singleCost
            } else {
                dp[idx + 1] = singleCost
                for (j in idx + 2..s.size) {
                    dp[j] = minOf(doubleCost + (s[j - 1].l - a[i]), singleCost + 2L * (s[j - 1].l - a[i]))
                    if (j == s.size || left[j] != i) {
                        bestSoFar = dp[j]
                        dp[j] = INF
                        break
                    }
                }
            }
        }
        ans.add(bestSoFar)
    }
    println(ans.joinToString("\n"))
}

data class Segment(val l: Int, val r: Int)