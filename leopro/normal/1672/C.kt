fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        if ((1 until a.size).count { a[it - 1] == a[it] } <= 1) return@repeat println(0)
        val bad = (1 until a.size).filter { a[it - 1] == a[it] }
        println((bad.last() - bad.first()).let { if (it == 1) 1 else it - 1 })
    }
}