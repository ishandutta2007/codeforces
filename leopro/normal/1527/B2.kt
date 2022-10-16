fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        if (s.reversed() != s) {
            println(if (s.length % 2 == 1 && s[n / 2] == '0' && s.count { it == '0' } == 2) "DRAW" else "ALICE")
        } else {
            println(if (s.count { it == '0' }.let { it == 1 || it % 2 == 0 }) "BOB" else "ALICE")
        }
    }
}

fun Boolean.toInt() = if (this) 1 else 0

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)