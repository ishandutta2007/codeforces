fun main() {
    val (n, k) = readInts()
    val p = readInts().sorted()
    val dp = Array(n + 1) { Array(k + 1) { LongArray(k + 1) { -8_000_000_000L } } }
    dp[0][0][0] = 0
    for (i in p.indices) {
        val prev = dp[i]
        val cur = dp[i + 1]
        for (a in 0..k) {
            for (b in 0..k) {
                if (a == b) cur[a][b] = prev[a][b]
                if (a > 0) cur[a][b] = maxOf(cur[a][b], prev[a - 1][b] - p[i])
                if (a >= b && b > 0) cur[a][b] = maxOf(cur[a][b], prev[a][b - 1] + p[i])
            }
        }
    }
    println(dp[n][k][k])
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()