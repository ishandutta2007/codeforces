fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        if (a == a.sorted()) return@repeat println(0)
        if (a.first() == n && a.last() == 1) return@repeat println(3)
        if (a.first() == 1 || a.last() == n) return@repeat println(1)
        println(2)
    }
}

fun Boolean.toInt() = if (this) 1 else 0

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)