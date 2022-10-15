fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        println(if (s.count { it == '0' }.let { it == 1 || it % 2 == 0 }) "BOB" else "ALICE")
    }
}

fun Boolean.toInt() = if (this) 1 else 0

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)