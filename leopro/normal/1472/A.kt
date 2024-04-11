fun main() {
    repeat(readLine()!!.toInt()) {
        val (w, h, n) = readLine()!!.split(' ').map { it.toInt() }
        println(if (n <= w.takeLowestOneBit() * h.takeLowestOneBit()) "YES" else "NO")
    }
}