fun main() {
    repeat(readLine()!!.toInt()) {
        val k = readLine()!!.toInt()
        println(100 / gcd(k, 100 - k))
    }
}

fun Boolean.toInt() = if (this) 1 else 0

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)