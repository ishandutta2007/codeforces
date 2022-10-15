fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toLong() }
    val prefixMax = LongArray(n + 1) { Long.MIN_VALUE }
    val suffixMax = LongArray(n + 1) { Long.MIN_VALUE }
    for (i in a.indices) prefixMax[i + 1] = maxOf(prefixMax[i], a[i])
    for (i in a.indices.reversed()) suffixMax[i] = maxOf(suffixMax[i + 1], a[i])
    fun maxWithout(i: Int) = maxOf(prefixMax[i], suffixMax[i + 1])
    val sum = a.sum()
    val ans = a.indices.filter { maxWithout(it) * 2 == sum - a[it] }.map { it + 1 }
    println(ans.size)
    println(ans.joinToString(" "))
}