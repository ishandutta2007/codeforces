import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val ans = mutableListOf<Int>()
        readLine()
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val records = TreeSet<Int>()
        var min = Int.MAX_VALUE
        for (i in a.indices) {
            if (a[i] < min) {
                min = a[i]
                records.add(i)
            }
        }
        repeat(m) {
            val (k, d) = readLine()!!.split(' ').map { it.toInt() }
            val i = k - 1
            a[i] -= d
            if (i != 0) {
                records.remove(i)
                val j = records.lower(i)!!
                if (a[i] < a[j]) records.add(i)
            }
            while (true) {
                val j = records.higher(i)
                if (j == null || a[j] < a[i]) break
                records.remove(j)
            }
            ans.add(records.size)
        }
        println(ans.joinToString(" "))
    }
}