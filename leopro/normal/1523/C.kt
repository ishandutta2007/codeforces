fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val current = mutableListOf<Int>()
        repeat(n) {
            val next = readLine()!!.toInt()
            if (next == 1) {
                current.add(1)
            } else {
                while (current.removeLast() + 1 != next) {
                }
                current.add(next)
            }
            println(current.joinToString("."))
        }
    }
}