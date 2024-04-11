fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        println(n.takeHighestOneBit() - 1)
    }
}

fun Boolean.toInt() = if (this) 1 else 0

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)