fun main() {
    repeat(readLine()!!.toInt()) {
        val x = readLine()!!.toInt()
        if (x.toString(2).count { it == '1' } != 1) return@repeat println(x - (x and (x - 1)))
        if (x == 1) println(3) else println(x + 1)
    }
}