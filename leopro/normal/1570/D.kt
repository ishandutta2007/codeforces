import java.util.*

fun main() {
    val reachable = TreeSet<Int>()
    val x = readLine()!!.toInt()
    var cur = x
    while (cur !in reachable) {
        reachable.add(cur)
        cur++
        while (cur % 10 == 0) cur /= 10
    }
    println(reachable.size)
}