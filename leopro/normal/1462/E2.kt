const val MOD = 1_000_000_007
fun Int.toModInt() = ModInt(this)
fun Long.toModInt() = ModInt(this.toInt())

inline class ModInt(private val value: Int) {
    operator fun plus(other: ModInt) = (value + other.value).let { if (it >= MOD) it - MOD else it }.toModInt()
    operator fun times(other: ModInt) = (value.toLong() * other.value % MOD).toModInt()
    operator fun div(other: ModInt) = this * other.inverse()
    private fun inverse() = power(MOD - 2)
    private fun power(exp: Int): ModInt =
        if (exp == 0) 1.toModInt() else power(exp / 2).let { it * it } * if ((exp and 1) == 1) this else 1.toModInt()

    fun toInt() = value
}

fun main() {
    val factorial = Array(200_001) { 1.toModInt() }
    for (i in 1 until factorial.size) factorial[i] = factorial[i - 1] * i.toModInt()
    fun C(n: Int, k: Int) = if (n < k) 0.toModInt() else factorial[n] / factorial[k] / factorial[n - k]
    repeat(readLine()!!.toInt()) {
        val (_, m, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
        a.mapIndexed { r, value ->
            val l = a.firstAtLeast(value - k)
            C(r - l, m - 1)
        }.reduce { a, b -> a + b }.let { println(it.toInt()) }
    }
}

fun IntArray.firstAtLeast(value: Int): Int {
    var pos = -1
    for (shift in generateSequence(size.takeHighestOneBit()) { it / 2 }.takeWhile { it > 0 }) {
        if ((pos + shift) in this.indices && this[pos + shift] < value) pos += shift
    }
    return pos + 1
}