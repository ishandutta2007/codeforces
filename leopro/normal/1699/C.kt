fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val z = a.indexOf(0)
        val b = IntArray(n) { -1 }
        b[z] = 0
        run {
            var minAbsent = 0
            val seen = BooleanArray(n + 1)
            fun add(x: Int) {
                seen[x] = true
                while (seen[minAbsent]) minAbsent++
            }
            for (i in 0..z) add(a[i])
            for (i in z + 1 until n) {
                if (a[i] == minAbsent) b[i] = a[i]
                add(a[i])
            }
        }
        run {
            var minAbsent = 0
            val seen = BooleanArray(n + 1)
            fun add(x: Int) {
                seen[x] = true
                while (seen[minAbsent]) minAbsent++
            }
            for (i in z until n) add(a[i])
            for (i in z - 1 downTo 0) {
                if (a[i] == minAbsent) b[i] = a[i]
                add(a[i])
            }
        }
        val f = Array(n + 1) { ONE }
        for (i in 2..n) f[i] = f[i - 1] * i
        fun C(n: Int, k: Int) = f[n] / f[n - k]
        val unseen = BooleanArray(n) { true }
        for (x in b) if (x != -1) unseen[x] = false
        val c = b.indices.filter { b[it] != -1 }.toIntArray()
        var i1 = c.indexOf(z)
        var i2 = c.indexOf(z)
        var cur = 0
        var free = 0
        var ans = ONE
        while (i1 > 0 || i2 + 1 < c.size) {
            if (i1 == 0 || (i2 + 1 != c.size && b[c[i1 - 1]] > b[c[i2 + 1]])) {
                ans *= C(free, b[c[i2 + 1]] - cur - 1)
                free += c[i2 + 1] - c[i2]
                free -= b[c[i2 + 1]] - cur
                cur = b[c[i2 + 1]]
                i2++
            } else {
                ans *= C(free, b[c[i1 - 1]] - cur - 1)
                free +=c[i1]- c[i1 - 1]
                free -= b[c[i1 - 1]] - cur
                cur = b[c[i1 - 1]]
                i1--
            }
        }
        println(ans * C(free, free))
    }
}


const val MOD: Int = 1e9.toInt() + 7
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