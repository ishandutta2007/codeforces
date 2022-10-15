fun main() {
    repeat(readLine()!!.toInt()) {
        val (start, period) = readLine()!!.split(' ')
        val p = period.toInt()
        var s = start.split(":").map { it.toInt() }.run { first() * 60 + last() }
        val palindromes = HashSet<Int>()
        repeat(24 * 60) {
            if (s.isPalindrome()) palindromes.add(s)
            s += p
            s %= 24 * 60
        }
        println(palindromes.size)
    }
}

private fun Int.isPalindrome(): Boolean {
    val h = this / 60
    val m = this % 60
    return h.toString().padStart(2, '0').reversed() == m.toString().padStart(2, '0')
}