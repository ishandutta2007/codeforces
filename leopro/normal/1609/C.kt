fun main() {
    val primes = mutableListOf<Int>()
    for (i in 2..1_000_000) {
        var isPrime = true
        for (prime in primes) {
            if (i % prime == 0) {
                isPrime = false
                break
            }
            if (prime * prime > i) break
        }
        if (isPrime) {
            primes.add(i)
        }
    }
    val isPrime = BooleanArray(1_000_001)
    for (prime in primes) isPrime[prime] = true

    repeat(readLine()!!.toInt()) {
        val (n, e) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val isNotOne = BooleanArray(n) { a[it] != 1 }
        val pref = IntArray(n + e)
        for (i in e until n + e) {
            pref[i] = isNotOne[i - e].toInt() + pref[i - e]
        }
        var ans = 0L
        for (i in 0 until n) {
            if (!isPrime[a[i]]) continue
            val toLeft = run {
                var l = 0
                var r = n
                while (r - l > 1) {
                    val m = (l + r) / 2
                    if (i - e * 1L * m >= 0 && pref[i] == pref[i - e * m]) l = m else r = m
                }
                l
            }
            val toRight = run {
                var l = 0
                var r = n
                while (r - l > 1) {
                    val m = (l + r) / 2
                    if (i + e + e * 1L * m < pref.size && pref[i + e] == pref[i + e + e * m]) l = m else r = m
                }
                l
            }
            ans += (toLeft + 1) * 1L * (toRight + 1) - 1L
        }
        println(ans)
    }
}

private fun Boolean.toInt() = if (this) 1 else 0