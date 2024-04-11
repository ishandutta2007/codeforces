fun main() {
    val n = readLong()
    println(fact(n) / fact(n / 2).square() * fact(n / 2 - 1).square() / 2)
}

fun Long.square() = this * this

fun fact(n: Long): Long = if (n < 2) 1 else fact(n - 1) * n

fun readLong() = readLine()!!.toLong()
fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()