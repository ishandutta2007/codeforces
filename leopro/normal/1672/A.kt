fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val sum = readLine()!!.split(' ').map { it.toInt() }.sumOf { it }
        println(if ((sum - n) % 2 == 1) "errorgorn" else "maomao90")
    }
}