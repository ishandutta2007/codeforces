fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val count = IntArray(n + 1)
        val pos = List(n + 1) { mutableListOf<Int>() }
        for (x in a) count[x]++
        for (i in a.indices) pos[a[i]].add(i)
        val counts = count.withIndex().sortedBy { it.value }
        val b = IntArray(n)
        fun link(x: Int, y: Int) {
            val i = pos[x].removeLast()
            b[i] = y
        }
        for (i in 1 until counts.size) {
            repeat(counts[i - 1].value) {
                link(counts[i - 1].index, counts[i].index)
            }
        }
        for (i in 1 until counts.size) {
            repeat(counts[i].value - counts[i - 1].value) {
                link(counts.last().index, counts[i].index)
            }
        }
        println(b.joinToString(" "))
    }
}