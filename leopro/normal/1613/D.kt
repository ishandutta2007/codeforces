import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() + 1 }.toIntArray()
        val res = solve(n, a)
        println(res)
    }
}

private fun stress(n: Int, a: IntArray): ModInt {
    var cnt = 0.toModInt()
    for (mask in 0 until (1 shl n)) {
        val cur = mutableListOf<Int>()
        var ok = true
        for (bit in 0 until n) {
            if (mask and (1 shl bit) == 0) continue
            cur.add(a[bit])
            if (abs(mex(cur) - a[bit]) > 1) ok = false
        }
        if (ok) cnt += 1
    }
    return cnt - 1
}

fun mex(lst: List<Int>): Int {
    for (i in 0 until lst.size + 3) {
        if (i !in lst) return i
    }
    return -2
}

private fun solve(n: Int, a: IntArray): ModInt {
    val ans = MutableList(n + 2) { ModInt(0) }
    val final = MutableList(n + 4) { ModInt(0) }
    ans[0] = ModInt(1)
    for (i in 0 until n) {
        ans[a[i]] = ans[a[i]] + ans[a[i]] + ans[a[i] - 1]
        if (a[i] >= 2) {
            final[a[i]] = ans[a[i] - 2] + final[a[i]] + final[a[i]]
        }
        final[a[i] + 2] = final[a[i] + 2] + final[a[i] + 2]
    }
    return ans.reduce { a, b -> a + b } + final.reduce { a, b -> a + b } - 1.toModInt()
}

const val MOD: Int = 998244353

fun Int.toModInt() = ModInt((this % MOD).let { if (it < 0) it + MOD else it })
fun Long.toModInt() = ModInt((this % MOD).let { if (it < 0) it + MOD else it })

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