fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val (s, t) = readLine()!!.split(' ').map { it.toInt() - 1 }
        val g = List(n) { mutableListOf<Int>() }
        for (j in 0 until m) {
            val (u, v) = readLine()!!.split(' ').map { it.toInt() - 1 }
            g[u].add(v)
            g[v].add(u)
        }
        val d = IntArray(n) { n }
        d[s] = 0
        val bfs = ArrayDeque<Int>()
        bfs.add(s)
        while (bfs.isNotEmpty()) {
            val cur = bfs.removeFirst()
            for (next in g[cur]) {
                if (d[next] > d[cur] + 1) {
                    d[next] = d[cur] + 1
                    bfs.addLast(next)
                }
            }
        }
        val with = List(n + 2) { mutableListOf<Int>() }
        for (i in 0 until n) with[d[i]].add(i)
        var count0 = Array(n) { ZERO }
        var count1 = Array(n) { ZERO }
        count0[s] = ONE
        var ans = ZERO
        for (curD in 0..d[t]) {
            for (cur in with[curD]) {
                for (next in g[cur]) {
                    if (d[next] == d[cur] + 1) {
                        count0[next] += count0[cur]
                    }
                    if (d[next] == d[cur]) {
                        count1[next] += count0[cur]
                    }
                }
            }
            if (curD != 0) for (cur in with[curD - 1]) {
                for (next in g[cur]) {
                    if (d[next] == d[cur] + 1) {
                        count1[next] += count1[cur]
                    }
                }
            }
            if (curD + 1 == d[t]) ans += count0[t]
            if (curD == d[t]) ans += count1[t]
        }
        println(ans)
    }
}

const val MOD: Int = 1e9.toInt() + 7
val ZERO = ModInt(0)
val ONE = ModInt(1)
val TWO = ModInt(2)
val THREE = ModInt(3)
val TEN = ModInt(10)

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