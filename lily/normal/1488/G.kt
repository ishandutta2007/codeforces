import java.util.*

    class qr(val first: Int, val second: Int) : Comparable<qr> {
        override fun compareTo(o2: qr): Int {
            val fr = first.compareTo(o2.first)
            return if (fr == 0) second.compareTo(o2.second)
            else fr
        }
    }

    fun main() {

        val n = readLine()!!.toInt()
        val c = IntArray(n + 1)
        val s = TreeSet<qr>()
        val l = Array(n + 1) { mutableListOf<Int>() }
        for (i in 1..n) c[i] = 0
        val ans = mutableListOf<Long>()
        var tot = 0L
        for (i in 1..n)
            for (j in (i * 2)..n step i) {
                c[j]++
                l[j].add(i)
            }
        for (i in 1..n) s.add(qr(c[i], i))
        while (s.size > 0) {
            val delta = s.last().first
            val i = s.last().second
            tot += delta
            ans.add(tot)
            s.remove(qr(delta, i))
            for (j in l[i]) {
                s.remove(qr(c[j], j))
                c[j]--
                s.add(qr(c[j], j))
            }
        }
        println( ans.joinToString(" "))
    }