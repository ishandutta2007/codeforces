import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val (N, M) = readLine()!!.split(' ').map { it.toInt() }
        val B: MutableList<List<Int>> = (0 until N).map { readLine()!!.split(' ').map { it.toInt() } }.toMutableList()
        B += listOf(2000000000, 2000000000)
        val A = B.withIndex().groupBy { it.value[0] }


        val S: SortedSet<Pair<Int,Int>> = TreeSet(kotlin.Comparator { o1, o2 ->
            if (o1.first != o2.first) o1.first - o2.first
            else o1.second - o2.second
        })
        val D = IntArray(N) { 0 }
        var last = 0
        for (a in A.keys.sorted()) {
            val cur = a
            for (d in last until cur) {
                if (S.isEmpty()) break
                for (i in 0 until M) {
                    if (S.isEmpty()) break
                    val f = S.first()
                    D[f.second] = d
                    S.remove(f)
                }
            }
            for (b in A[a]!!) {
                S.add(b.value[1] to b.index)
            }
            last = cur
        }
        val diff = B.zip(D.toList()).map { max(0, it.second - it.first[1]) }.max()
        println(diff)
        println(D.joinToString(" ") { it.toString() })
    }
}