fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k, m) = readLine()!!.split(' ').map { it.toInt() }
        val b = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val rem = (1..n).filter { b.binarySearch(it) < 0 }
        val half = k / 2
        println(if ((n - m) % (2 * half) == 0 && b.any { it in rem[half - 1]..rem[rem.size - half] }) "YES" else "NO")
    }
}