//This code was created by LeoPro with great help of IntelliJ IDEA

import kotlin.math.min

fun cube(a: Long): Long = a * a * a

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)
fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)

fun lcm(a: Long, b: Long): Long = a * b / gcd(a, b)

fun extractPeriods(p: IntArray, x: IntArray): IntArray {
    var minLcm = cube((x.max()!!).toLong())
    for (i in 1..x.size - 2) {
        val cur = lcm(lcm((x[i] - x[i - 1]).toLong(), (x[i + 1] - x[i]).toLong()), (x[i + 1] - x[i - 1]).toLong())
        minLcm = min(minLcm, cur)
    }
    return p.filter { minLcm % it == 0L }.toIntArray()
}

fun remGcd(moments: IntArray, s: Int, p: Int): Int {
    val first = moments.find { it % p != moments[s] % p } ?: return 0
    var ans = 0
    for (x in moments) {
        if (x % p != moments[s] % p) {
            ans = gcd(ans, x - first)
        }
    }
    return ans
}

fun main() {
    readLine()
    val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val moments = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val periods = extractPeriods(a, moments)
    val divider = IntArray(1_000_001)
    divider.fill(0)
    for (p in a) {
        for (m in 0..1_000_000 / p) {
            divider[p * m] = p
        }
    }
    for (p in periods) {
        for (i in 0 until min(moments.size, 2)) {
            if (divider[remGcd(moments, i, p)] != 0) {
                println("YES")
                println(
                    moments[i].toString() + ' ' + p + '\n' +
                            (moments.find { it % p != moments[i] % p } ?: "1").toString() + ' '
                            + divider[remGcd(moments, i, p)].toString()
                )
                return
            }
        }
    }
    println("NO")
}