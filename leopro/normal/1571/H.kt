fun main() {
    val (n, a, b) = readLine()!!.split(' ').map { it.toInt() }.let { (n, a, b) -> listOf(n, a * 2, b * 2) }
    val hor = BooleanArray(a)
    val ver = BooleanArray(b)
    val sideNot = Array(a + b - 1) { ONE }
    val mainNot = Array(a + b - 1) { ONE }
    repeat(n) {
        readLine()!!.split(' ').map { it.toInt() }.let { (q, r, s) ->
            val x = 2 * q
            val y = 2 * r
            val p = s.toModInt() / 1_000_000
            hor[x] = true
            ver[y] = true
            sideNot[x + y] *= ONE - p
            mainNot[x - y + b - 1] *= ONE - p
        }
    }
    var ans = ONE + hor.sumOf { (it.toInt()) } + ver.sumOf { it.toInt() } + sideNot.sumOf { ONE - it } + mainNot.sumOf { ONE - it }
    for (x in 1 until a) {
        for (y in 1 until b) {
            val cnt = hor[x].toInt() + ver[y].toInt()
            ans += (ONE - sideNot[x + y]) * (ONE - mainNot[x - y + b - 1]) * (cnt + 1)
            ans += (ONE - sideNot[x + y]) * mainNot[x - y + b - 1] * cnt
            ans += sideNot[x + y] * (ONE - mainNot[x - y + b - 1]) * cnt
            ans += sideNot[x + y] * mainNot[x - y + b - 1] * (cnt - 1).coerceAtLeast(0)
        }
    }
    println(ans)
}

fun <T> Array<T>.sumOf(transform: (T) -> ModInt) = fold(ZERO) { acc, cur -> acc + transform(cur) }
fun Boolean.toInt() = if (this) 1 else 0
val ONE = 1.toModInt()
val ZERO = 0.toModInt()
const val MOD: Int = 998244353

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