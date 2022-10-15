fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val code = readLine()!!
        val value = IntArray(n + 1)
        for (i in code.indices) value[i + 1] = value[i] + (if (code[i] == '+') 1 else -1)
        val prefixMax = IntArray(n + 1)
        val prefixMin = IntArray(n + 1)
        val suffixMax = IntArray(n + 1) { value.last() }
        val suffixMin = IntArray(n + 1) { value.last() }
        for (i in 1..n) prefixMax[i] = maxOf(prefixMax[i - 1], value[i])
        for (i in 1..n) prefixMin[i] = minOf(prefixMin[i - 1], value[i])
        for (i in code.indices.reversed()) suffixMax[i] = maxOf(suffixMax[i + 1], value[i])
        for (i in code.indices.reversed()) suffixMin[i] = minOf(suffixMin[i + 1], value[i])

        repeat(m) {
            val (l, r) = readLine()!!.split(' ').map { it.toInt() }
            val max =
                if (r < n) maxOf(prefixMax[l - 1], value[l - 1] - value[r] + suffixMax[r + 1]) else prefixMax[l - 1]
            val min =
                if (r < n) minOf(prefixMin[l - 1], value[l - 1] - value[r] + suffixMin[r + 1]) else prefixMin[l - 1]
            println(max - min + 1)
        }
        println()
    }
}