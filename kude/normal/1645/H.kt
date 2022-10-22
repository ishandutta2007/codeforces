import kotlin.math.max
import kotlin.math.min

const val INF = 1001001001

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    val dp0 = IntArray(n) { -INF }
    val dp1 = IntArray(n) { INF }
    dp0[0] = INF
    dp1[0] = -INF
    for (i in 1 until n) {
        for ((x, y) in arrayOf(a[i - 1] to dp0[i - 1], dp1[i - 1] to a[i - 1])) {
            if (x < a[i]) dp0[i] = max(dp0[i], y)
            if (y > a[i]) dp1[i] = min(dp1[i], x)
        }
    }
    val ans = IntArray(n)
    ans[n - 1] = if (dp0[n - 1] != -INF) 0 else if (dp1[n - 1] != INF) 1 else -1
    if (ans[n - 1] == -1) {
        println("NO")
        return
    }
    for (i in n - 2 downTo 0) {
        val (x, y) = if (ans[i + 1] == 0) a[i + 1] - 1 to dp0[i + 1] else dp1[i + 1] to a[i + 1] + 1
        ans[i] = if (a[i] <= x && y <= dp0[i]) 0 else 1
    }
    println("YES")
    println(ans.joinToString(" "))
}