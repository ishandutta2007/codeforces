import java.lang.Long.max

fun main() {
    val (N, M, K) = readLine()!!.split(' ').map { it.toInt() }
    val A = readLine()!!.split(' ').map { it.toLong() }
    val B = readLine()!!.split(' ').map { it.toLong() }
    val C = (0 until N).map { readLine()!!.split(' ').map { it.toLong() } }

    val AOpen = (0 until N).map { i ->
        A[i] to (0 until B.count { it <= A[i] }).map { j -> C[i][j] }.max()!!
    }
    val BOpen = (0 until M).map { i ->
        B[i] to (0 until A.count { it <= B[i] }).map { j -> C[j][i] }.max()!!
    }

    val open = (AOpen + BOpen).sortedBy { it.first }
    val ans = (0 until N+M).map { i ->
        var ans = 0L
        var cur = 0L
        var mx = open[0].second + (if (i == 0) K else 0)
        (1 until N+M).forEach {
            val missing = (open[it].first - cur + mx - 1) / mx
            cur += missing * mx
            ans += missing
            var self = open[it].second + (if (i == it) K else 0)
            mx = max(mx, self)
        }

        ans
    }.min()
    println(ans)
}