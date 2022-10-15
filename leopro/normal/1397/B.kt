import java.util.Arrays.parallelPrefix
import kotlin.math.abs

fun main() {
    val n = readLine()!!.toInt()
    if (n <= 2) {
        println(readLine()!!.split(' ').map { it.toInt() }.take(1).sum() - 1)
        return
    }
    if (n > 32) {
        println(readLine()!!.split(' ').map { it.toLong() }.sum() - n)
        return
    }
    val a = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
    a.sort()
    var prev = a.sum()
    for (c in 1..1_000_000_000) {
        val powers = LongArray(n) { if (it == 0) 1 else c.toLong() }
        parallelPrefix(powers) { x, y -> x * y }
        val ans = a.zip(powers) { x, y -> abs(x - y) }.sum()
        if (ans > prev) {
            println(prev)
            return
        } else {
            prev = ans
        }
    }
}