fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!.map { it - 'a' }.toIntArray()
    val f = readLine()!!.map { it - 'a' }.toIntArray()
    val res = IntArray(n)
    for (i in res.indices.reversed()) {
        res[i] += s[i] + f[i]
        if (i > 0 && res[i] >= 26) res[i] -= 26.also { res[i - 1] += 1 }
    }
    for (i in res.indices) {
        if (res[i] % 2 == 1) res[i + 1] += 26
        res[i] /= 2
    }
    println(res.map { 'a' + it }.joinToString(""))
}