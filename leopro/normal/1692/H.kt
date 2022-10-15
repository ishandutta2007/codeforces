import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val ind = TreeMap<Int, MutableList<Int>>()
        for (i in a.indices) {
            ind[a[i]] = ind.getOrDefault(a[i], mutableListOf()).apply { add(i) }
        }
        var max = 0
        var l = 0
        var r = 0
        var w = 0
        for (row in ind) {
            var cur = 0
            var minLOf = 1
            var minLBy = 0
            var p = -1
            for (i in row.value) {
                cur += 2 - (i - p)
                p = i
                if (cur <= minLOf) {
                    minLOf = cur
                    minLBy = i
                }
                if (cur - minLOf >= max) {
                    max = cur - minLOf
                    l = minLBy
                    r = i
                    w = row.key
                }
            }
        }
        println("$w ${l.plus(1)} ${r.plus(1)}")
    }
}