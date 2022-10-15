fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() - 1 }
        val indices = List(n) { mutableListOf<Int>() }
        for (i in a.indices) indices[a[i]].add(i)
        val color = IntArray(n)
        val date = IntArray(n) { -1 }
        var d = 0
        var i = 0
        for (entry in indices) {
            if (entry.size >= k) {
                for (i in 0 until k) color[entry[i]] = i + 1
            } else {
                for (j in entry) {
                    color[j] = i++ % k + 1
                    date[j] = d++
                }
                i %= k
            }
        }
        val r = d / k * k
        for (i in 0 until n) if (date[i] >= r) color[i] = 0
        println(color.joinToString(" "))
    }
}