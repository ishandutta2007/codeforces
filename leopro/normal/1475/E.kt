const val MOD = 1_000_000_007

inline class ModInt(private val value: Int) {
    constructor(value: Long) : this((value % MOD).toInt())

    operator fun plus(other: ModInt) = ModInt((value + other.value).let { if (it >= MOD) it - MOD else it })
    operator fun times(other: ModInt) = ModInt(value * 1L * other.value)
    private fun power(exp: Int): ModInt = if (exp == 0) ModInt(1) else ModInt(listOf(1, value)[exp % 2]) * power(exp / 2).let { it * it }
    operator fun div(other: ModInt) = this * other.power(MOD - 2)

    override fun toString() = value.toString()
}

fun Int.toModInt() = ModInt(this)

fun main() {
    val factorial = Array(2000) { ModInt(1) }
    for (i in 1 until factorial.size) factorial[i] = factorial[i - 1] * i.toModInt()
    fun c(n: Int, k: Int): ModInt {
        return if (n < k) 0.toModInt() else {
            val f = factorial[n] / factorial[k]
            f / factorial[n - k]
        }
    }
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sortedDescending().toIntArray()
        val least = a[k - 1]
        val takeCount = (0 until k).count { a[it] == least }
        val allCount = (0 until n).count { a[it] == least }
        println(c(allCount, takeCount))
    }
}