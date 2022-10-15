import kotlin.math.absoluteValue

fun main() {
    readLine()
    val a = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
    val b = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
    val g = (1 until a.size).fold(0L) { acc, idx -> gcd(a[idx] - a[idx - 1], acc) }.absoluteValue
    println(b.map { gcd(it + a[0], g) }.joinToString(" "))
}

fun gcd(x: Long, y: Long): Long = if (x == 0L) y else gcd(y % x, x)