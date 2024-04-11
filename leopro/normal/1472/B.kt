fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val sum = a.sum()
        println(if (sum % 4 == 0 || sum % 2 == 0 && a.find { it == 1 } != null) "YES" else "NO")
    }
}