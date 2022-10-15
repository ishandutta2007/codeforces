fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val b = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val c = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        if (b.find { it == c.last() } == null) return@repeat println("NO")
        val finishColors = Array(n + 1) { mutableListOf<Int>() }
        for (i in a.indices.filter { a[it] != b[it] }) finishColors[b[i]].add(i)
        val count = IntArray(n + 1)
        for (color in c) count[color]++
        if (count.indices.find { count[it] < finishColors[it].size } != null) {
            println("NO")
        } else {
            println("YES")
            val free = b.indices.find { a[it] != b[it] && b[it] == c.last() } ?: b.indexOf(c.last())
            for (color in c) {
                print("${(if (finishColors[color].isEmpty()) free else finishColors[color].removeLast()) + 1} ")
            }
            println()
        }
    }
}