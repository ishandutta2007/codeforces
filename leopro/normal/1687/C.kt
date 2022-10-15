import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val b = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val d = IntArray(n)
        for (i in d.indices) d[i] = a[i] - b[i]
        val pref = LongArray(n + 1)
        for (i in d.indices) pref[i + 1] = pref[i] + d[i]
        val s = List(m) { readLine()!!.split(' ').map { it.toInt() }.run { Segment(first() - 1, last()) } }
        val ind = List(n + 1) { mutableListOf<Int>() }
        for (i in s.indices) ind[s[i].l].add(i)
        for (i in s.indices) ind[s[i].r].add(i)
        val zero = BooleanArray(m)
        val unprocessed = mutableListOf<Int>()
        fun check(i: Int) {
            if (zero[i]) return
            if (pref[s[i].l] == 0L && pref[s[i].r] == 0L) zero[i] = true
            if (zero[i]) unprocessed.add(i)
        }
        for (i in s.indices) check(i)
        val unzeroes = TreeSet<Int>()
        for (i in 0 until n) unzeroes.add(i)
        while (unprocessed.isNotEmpty()) {
            val i = unprocessed.removeLast()
            val (l, r) = s[i]
            while (true) {
                val x = unzeroes.higher(l - 1)
                if ((x ?: (r + 1)) > r) break
                unzeroes.remove(x!!)
                pref[x] = 0L
                for (idx in ind[x]) check(idx)
            }
        }
        println(if (pref.all { it == 0L }) "YES" else "NO")
    }
}

data class Segment(val l: Int, val r: Int)