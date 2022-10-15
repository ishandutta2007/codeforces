fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val mn = a.minOf { it }
        val ans = mutableListOf<Pair<Int, Int>>()
        for (v in a.filter { it > mn }) {
            ans.add(v to mn)
        }
        println(ans.slice(0 until n / 2).joinToString("\n") { it.run { "$first $second" } })
    }
}