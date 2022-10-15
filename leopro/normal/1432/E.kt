fun main() {
    repeat (readLine()!!.toInt()) {
        val (n, k) = readLongs()
        val s = readLine()!!
        val onesCount = IntArray(s.length)
        for (i in s.indices) if (s[i] == '1') onesCount[i] = 1
        val prefixSum = onesCount.clone()
        for (i in 1..s.lastIndex) prefixSum[i] += prefixSum[i - 1]
        val onesCountBeforeZeros = prefixSum.filterIndexed { idx, _ -> s[idx] == '0' }
        if (k >= onesCountBeforeZeros.map { it.toLong() }.sum()) {
            println(s.toCharArray().sorted().joinToString(""))
        } else {
            var sum = 0L
            for ((index, cnt) in onesCountBeforeZeros.withIndex()) {
                if (sum + cnt > k) {
                    println('0'.times(index) + '1'.times((cnt - k + sum).toInt()) + '0' + '1'.times((k - sum).toInt()) +
                            s.substring((index + cnt + 1).toInt() until s.length))
                    return@repeat
                }
                sum += cnt
            }
        }
    }
}

fun Char.times(other: Int) = CharArray(other) { this }.joinToString("")
fun readLongs() = readLine()!!.split(' ').map { it.toLong() }