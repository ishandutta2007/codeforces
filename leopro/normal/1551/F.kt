fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val tree = List(n) { mutableListOf<Int>() }
        val dist = List(n) { i -> IntArray(n) { j -> if (i == j) 0 else (1e9).toInt() } }
        repeat(n - 1) {
            val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1 }
            tree[u].add(v)
            tree[v].add(u)
            dist[u][v] = 1
            dist[v][u] = 1
        }
        for (through in 0 until n) {
            for (i in 0 until n) {
                for (j in 0 until n) {
                    dist[i][j] = minOf(dist[i][j], dist[i][through] + dist[through][j])
                }
            }
        }
        var ans = 0.toModInt()
        if (k == 2) {
            ans += n
            ans *= (n - 1)
            return@repeat println(ans / 2)
        }

        for (center in 0 until n) {
            val adjacent = tree[center]
            if (adjacent.size < k) continue
            val count = List(n + 1) { IntArray(adjacent.size) }
            for (i in 0 until n) {
                if (i == center) continue
                for (j in adjacent.indices) {
                    if (dist[i][center] != dist[i][adjacent[j]] + 1) continue
                    count[dist[i][center]][j]++
                }
            }
            for (d in 0..n) {
                val choice = count[d]
                val dp = List(choice.size + 1) { Array(k + 1) { 0.toModInt() } }
                dp[0][0] = 1.toModInt()
                for (i in 1 until dp.size) {
                    for (j in 0 until dp[i].size) {
                    if (j == 0) dp[i][j] = dp[i - 1][j] else
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * choice[i - 1]
                    }
                }
                ans += dp[choice.size][k]
            }
        }
        println(ans)
    }
}

const val MOD: Int = (1e9 + 7).toInt()

fun Int.toModInt() = ModInt(this % MOD)
fun Long.toModInt() = ModInt(this % MOD)

inline class ModInt(private val value: Int) {
    fun toInt() = value
    override fun toString() = "$value"

    constructor(value: Long) : this(value.toInt())

    operator fun plus(other: ModInt) = ModInt((value + other.value).let { if (it >= MOD) it - MOD else it })
    operator fun minus(other: ModInt) = ModInt((value - other.value).let { if (it < 0) it + MOD else it })
    operator fun times(other: ModInt) = ModInt((value * 1L * other.value) % MOD)
    operator fun div(other: ModInt) = this * other.inverse()

    operator fun plus(other: Int) = plus(other.toModInt())
    operator fun minus(other: Int) = minus(other.toModInt())
    operator fun times(other: Int) = times(other.toModInt())
    operator fun div(other: Int) = div(other.toModInt())

    fun inverse() = power(MOD - 2)
    fun power(exp: Int): ModInt = when {
        exp == 0 -> ModInt(1)
        exp % 2 == 0 -> power(exp / 2).let { it * it }
        else -> this * power(exp - 1)
    }
}

fun Boolean.toInt() = if (this) 1 else 0