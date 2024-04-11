import java.util.*

var sz = 200_000.takeHighestOneBit()
val subSize = IntArray(sz * 2)
val subSum = LongArray(sz * 2)

fun add(x: Long) = add(x.toInt(), 1)
fun remove(x: Long) = add(x.toInt(), -1)

fun add(x: Int, v: Int) {
    subSize[x + sz] += v
    subSum[x + sz] += x.toLong() * v
    var i = (x + sz) / 2
    while (i > 0) {
        subSum[i] = subSum[2 * i] + subSum[2 * i + 1]
        subSize[i] = subSize[2 * i] + subSize[2 * i + 1]
        i /= 2
    }
}

fun sumFirst(x: Int): Long {
    var i = 1
    var k = x
    var ans = 0L
    while (true) {
        if (i >= sz) return ans + (i - sz).toLong() * k
        val leftSize = subSize[2 * i]
        if (k <= leftSize) {
            i = 2 * i
        } else {
            ans += subSum[2 * i]
            k -= leftSize
            i = 2 * i + 1
        }
    }
}

fun main() {
    val (_, k, x) = readInts()
    val a = readLongArray() + LongArray(x) { 0L }
    val n = a.size
    var l = -1L
    var r = a.sum()
    while (r - l > 1) {
        val m = (l + r) / 2
        Arrays.fill(subSize, 0)
        Arrays.fill(subSum, 0)
        val mostLeft = IntArray(n) { n }
        for (i in a.indices) {
            for (j in i + subSize[1] until n) {
                if (subSize[1] >= x && sumFirst(x) <= m) break
                add(a[j])
            }
            if (sumFirst(x) <= m) mostLeft[i] = i + subSize[1] else break
            remove(a[i])
        }

        val dp = IntArray(n + 1) { n }
        dp[0] = 0
        for (i in mostLeft.indices) {
            dp[i + 1] = minOf(dp[i + 1], dp[i] + if (a[i] > 0) 1 else 0)
            if (mostLeft[i] < n) dp[mostLeft[i]] = minOf(dp[mostLeft[i]], dp[i] + (mostLeft[i] - i - x))
        }
        if (dp[n] > k) {
            l = m
        } else {
            r = m
        }
    }
    println(r)
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()