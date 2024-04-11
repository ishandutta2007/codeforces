fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
        if (n % 2 == 0 && m % 2 == 1) return@repeat println(if (k % 2 == 0 && k + (n / 2) <= n * m / 2) "YES" else "NO")
        if (n % 2 == 0) return@repeat println(if (k % 2 == 0) "YES" else "NO")
        if (n % 2 == 1) return@repeat println(if (k % 2 == (m / 2) % 2 && k >= (m / 2)) "YES" else "NO")
    }
}