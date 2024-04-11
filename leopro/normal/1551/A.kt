fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        when (n % 3) {
            0 -> println("${n / 3} ${n / 3}")
            1 -> println("${n / 3 + 1} ${n / 3}")
            2 -> println("${n / 3} ${n / 3 + 1}")
        }
    }
}