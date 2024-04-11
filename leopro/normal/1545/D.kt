fun main() {
    val (m, k) = readLine()!!.split(' ').map { it.toInt() }
    val coordinates = List(k) { readLine()!!.split(' ').map { it.toInt() } }
    val sum = coordinates.map { it.sum().toLong() }
    val sumSquared = coordinates.map { it.map { it * 1L * it }.sum() }
    val patterns = listOf(0 to 1, 0 to 2, 1 to 2).map { (i, j) -> progression(k, i, j, sum[i], sum[j]) }
    var y = -1
    for (pattern in patterns) {
        if (sum.indices.count { sum[it] != pattern[it] } == 1) {
            y = sum.indices.find { sum[it] != pattern[it] }!!
        }
    }
    val delta = sum[y] - (sum[y + 1] + sum[y - 1]) / 2
    val sumSquaredY = if (y in 1..2) {
        val a = sumSquared[y + 3] - sumSquared[y + 2]
        val b = sumSquared[y + 2] - sumSquared[y + 1]
        val c = 2 * b - a
        sumSquared[y + 1] - c
    } else {
        val a = sumSquared[y - 3] - sumSquared[y - 2]
        val b = sumSquared[y - 2] - sumSquared[y - 1]
        val c = 2 * b - a
        sumSquared[y - 1] - c
    }
    println("$y ${(sumSquared[y] - sumSquaredY - delta * delta) / 2 / delta}")
}

fun progression(n: Int, i: Int, j: Int, x: Long, y: Long) = List(n) {
    x + (y - x) * (it - i) / (j - i)
}