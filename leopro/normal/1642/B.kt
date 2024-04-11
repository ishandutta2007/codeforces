fun main() {
    val ans = mutableListOf<Int>()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val d = a.distinct().size
        for (k in 1..n) {
            ans.add(maxOf(d, k))
        }
    }
    println(ans.joinToString(" "))
}