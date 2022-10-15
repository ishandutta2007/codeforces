fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        val s = a.sum()
        if (s == n) return@repeat println(0)
        if (s < n) return@repeat println(1)
        println(s - n)
    }
}