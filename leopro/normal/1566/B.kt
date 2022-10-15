fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        if (s.none { it == '0' }) return@repeat println(0)
        if (s.matches("1*0+1*".toRegex())) return@repeat println(1)
        println(2)
    }
}