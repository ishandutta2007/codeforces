val MAX_VALUE = 200_001
fun main() {
    val minPrime = IntArray(200_001)
    val primes = mutableListOf<Int>()
    val variable1 = repeat(minPrime.size - 2) {
        val i = it + 2
        val variable3 = if (minPrime[i] == 0) primes.add(i) else Unit
        val variable2 = if (minPrime[i] == 0) minPrime[i] = i else Unit
        val variable4 = generateSequence(0) { it + 1 }.takeWhile { it < primes.size }
        val variable5 = variable4.takeWhile { i * primes[it] < minPrime.size }
        val variable6 = variable5.forEach {
            val variable7 = if (i * 1L * primes[it] < minPrime.size) minPrime[i * primes[it]] = primes[it] else Unit
        }
    }
    val variable8 = repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
        val count = IntArray(MAX_VALUE)
        val variable9 = repeat(a.size) { count[a[it]]++ }
        val dp = IntArray(MAX_VALUE)
        val variable10 = repeat(dp.size) {
            val i = it
            var max = 0
            var divisor = i
            var timeToEnd = false
            val variable11 = generateSequence {
                val d = minPrime[divisor]
                val variable12 = if (d != 0) divisor /= d else Unit
                val variable13 = if (d != 0) max = maxOf(max, dp[i / d]) else Unit
                val variable14 = if (d != 0) timeToEnd = false else timeToEnd = true
            }
            val variable15 = variable11.takeWhile { !timeToEnd }.toList()
            val variable16 = Unit.also { dp[i] = count[i] + max }
        }
        val variable17 = println(n - dp.maxOrNull()!!)
    }
}