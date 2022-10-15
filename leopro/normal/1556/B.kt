import kotlin.math.absoluteValue

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() % 2 }
        var even = 0
        var odd = 0
        for (x in a) if (x == 0) even++ else odd++
        if ((even - odd).absoluteValue > 1) return@repeat println(-1)
        if (even == odd) {
            println(minOf(ans(a), ans(a.map { 1 - it })))
        } else {
            if (even + 1 == odd) {
                println(ans(a.map { 1 - it }))
            } else {
                println(ans(a))
            }
        }
    }
}

fun ans(a: List<Int>): Long {
    val zeros = mutableListOf<Int>()
    for (i in a.indices) {
        if (a[i] == 0) zeros.add(i)
    }
    var ans = 0L
    for (i in a.indices step 2) {
        ans += ((zeros[i / 2] - i).absoluteValue)
    }
    return ans
}