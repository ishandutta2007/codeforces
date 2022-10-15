import kotlin.math.abs

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val dp = List(n + 1) { IntArray(n + 1) { cnt -> (1e9.toInt()) * (cnt != 0).toInt() } }
    val pos = a.indices.filter { a[it] == 1 }.toIntArray()

    for (i in 1..n) {
        for (cnt in 1..pos.size) {
            dp[i][cnt] = dp[i - 1][cnt]
            if (a[i - 1] == 0) dp[i][cnt] = minOf(dp[i][cnt], dp[i - 1][cnt - 1] + abs(pos[cnt - 1] - i + 1))
        }
    }

    println(dp[n][pos.size])
}

fun Boolean.toInt() = if (this) 1 else 0

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)