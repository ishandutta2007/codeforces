fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        if ('1' !in s) return@repeat println(0)
        val first = s.indexOfFirst { it == '1' }
        val last = s.indexOfLast { it == '1' }
        println(last - first + 1 - s.count { it == '1' })
    }
}