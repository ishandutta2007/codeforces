fun main() {
    val n = readLine()!!.toInt()
    val minPrime = IntArray(n + 1)
    val primes = mutableListOf<Int>()
    for (i in 2..n) {
        if (minPrime[i] == 0) {
            primes.add(i)
            minPrime[i] = i
        }
        for (m in primes.takeWhile { it <= minPrime[i] && it * i <= n }) minPrime[i * m] = m
    }
    val divisors = IntArray(n + 1)
    divisors[1] = 1
    for (i in 2..n) {
        var j = i
        var cnt = 0
        while (j % minPrime[i] == 0) j /= minPrime[i].also { cnt++ }
        divisors[i] = divisors[j] * (cnt + 1)
    }
    var ans = 0L
    val numbers = (1..n).sortedByDescending { n / it - divisors[it] }
    val answer = mutableListOf<Long>()
    for (i in numbers) {
        ans += n / i - divisors[i]
        answer.add(ans)
    }
    answer.removeLast()
    print(answer.reversed().joinToString(separator = " ", postfix = " "))
    println(0)
}

fun power(base: Int, exp: Int): Int = when {
    exp == 0 -> 1
    exp % 2 == 1 -> base * power(base, exp - 1)
    else -> power(base, exp / 2).let { it * it }
}