fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val s = readLine()!!
        val balance = IntArray(s.length + 1)
        for (i in s.indices) balance[i + 1] = balance[i] + if (s[i] == '(') 1 else -1
        val g = balance.count { it == 0 } - 1
        println(minOf(s.length / 2, g + k))
    }
}