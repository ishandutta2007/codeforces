import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split("\\s+".toRegex()).map { it.toInt() }.toIntArray()
        var ans = 0L
        for (i in 1 until a.size) ans += abs(a[i] - a[i - 1])
        var cur = minOf(ans - abs(a[0] - a[1]), ans - abs(a[a.size - 1] - a[a.size - 2]))
        for (i in 1 until a.size - 1) cur = minOf(cur, ans - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]) + abs(a[i - 1] - a[i + 1]))
        println(cur)
    }
}