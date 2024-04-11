fun main() {
    repeat(readLine()!!.toInt()) cases@{
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val g = List(n) { mutableListOf<Int>() }
        val r = List(n) { mutableListOf<Int>() }
        repeat(m) {
            val (x, y) = readLine()!!.split(' ').map { it.toInt() - 1 }
            g[x].add(y)
            r[y].add(x)
        }
        repeat(n) {
            if (a.all { it == 0 }) return@cases println(it)
            val isZero = BooleanArray(n) { a[it] == 0 }
            for (i in 0 until n) {
                if (!isZero[i]) {
                    g[i].forEach { a[it]++ }
                    a[i]--
                }
            }
        }
        val root = (0 until n).find { g[it].isEmpty() }!!
        val rem = (0 until n).map { g[it].size }.toIntArray()
        val order = mutableListOf<Int>()
        fun dfs(cur: Int) {
            order.add(cur)
            for (prev in r[cur]) {
                if (--rem[prev] == 0) dfs(prev)
            }
        }
        dfs(root)
        order.reverse()

        var time = ZERO
        val b = a.map { it.toModInt() }.toTypedArray()
        for (i in order) {
            for (j in g[i]) {
                b[j] += b[i]
            }
        }
        println(b[root] + n)
    }
}

const val MOD: Int = 998244353
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