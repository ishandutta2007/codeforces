import kotlin.math.sqrt

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val possible = (n % 2 == 0 && (n / 2).square()) || (n % 4 == 0 && (n / 4).square())
        println(if (possible) "YES" else "NO")
    }
}

fun Int.square(): Boolean {
    val rt = sqrt(this.toDouble()).toInt()
    for (i in rt - 1..rt + 1) if (i * i == this) return true
    return false
}