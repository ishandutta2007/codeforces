fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        if (n % 2 == 1) return@repeat println(-1)
        println("0 ${n / 2} ${n / 2}")
    }
}