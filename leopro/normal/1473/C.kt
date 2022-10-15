fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val end = n - k + 1
        val begin = k - end
        val p = IntArray(begin) { it + 1 } + IntArray(end) { begin + it + 1 }.reversedArray()
        println(p.joinToString(" "))
    }
}