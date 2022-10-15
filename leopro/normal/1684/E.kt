import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }
        val e = TreeSet<Int>()
        for (x in a) e.add(x)
        var mex = 0
        var f = k
        for (x in 0 until n) {
            if (x in e) mex++
            else if (f-- > 0) mex++
            else break
        }
        val count = TreeMap<Int, Int>()
        for (x in a) if (x > mex) count[x] = count.getOrDefault(x, 0) + 1
        val cnts = count.values.sortedDescending().toMutableList()
        f = k
        while (cnts.isNotEmpty() && f >= cnts.last()) cnts.removeLast().also { f -= it }
        println(cnts.size)
    }
}