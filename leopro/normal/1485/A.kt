fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(' ').map { it.toInt() }
        fun operations(a: Int, b: Int): Int {
            if (b == 1) return Int.MAX_VALUE
            if (a < b) return 1
            return operations(a / b, b) + 1
        }
        val cnt = minOf(operations(a, b), operations(a, b + 1) + 1)
        val ans = (0..cnt).minByOrNull { it + operations(a, b + it) }!!
        println(ans + operations(a, b + ans))
    }
}