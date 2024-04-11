const val MOD = 998244353

fun binaryPower(base: Long, exp: Int): Long = when {
    exp == 0 -> 1L
    exp % 2 == 1 -> base * binaryPower(base, exp - 1) % MOD
    else -> binaryPower(base, exp / 2).let { it * it % MOD }
}

fun main(){
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val f = LongArray(n + 1) { 1L }
        for (i in 2..n) f[i] = f[i - 1] * i % MOD
        val inv = LongArray(n + 1) { 1L }
        inv[n] = binaryPower(f[n], MOD - 2)
        for (i in n - 1 downTo 1) inv[i] = inv[i + 1] * (i + 1) % MOD
        val s = readLine()!!.toCharArray()
        var cur = '0'
        var cnt = 0
        var onePairs = 0
        var zeros = 0
        for (i in s.indices) {
            if (s[i] == cur) cnt++ else {
                if (cur == '1') onePairs += cnt / 2 else zeros += cnt
                cur = s[i]
                cnt = 1
            }
        }
        if (cur == '1') onePairs += cnt / 2 else zeros += cnt
        println(f[onePairs + zeros] * inv[zeros] % MOD * inv[onePairs] % MOD)
    }
}