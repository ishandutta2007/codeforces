fun main() {
    repeat(readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(' ').map { it.toInt() }.sorted()
        val maxHalf = (a + b + 1) / 2
        val minHalf = (a + b) / 2
        val ans: List<Int>
        val min = (minHalf - a)
        val max = a + b - min
        ans = (min..max step if ((a + b) % 2 == 0) 2 else 1).toList()
        println(ans.size)
        println(ans.joinToString(" "))
    }
}