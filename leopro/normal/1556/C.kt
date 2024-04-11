fun main() {
    val n = readLine()!!.toInt()
    val c = readLine()!!.split(' ').map { it.toInt() }
    var ans = 0L
    for (i in 0 until n) {
        var balance = 0L
        var minBalance = 0L
        for (j in i + 1 until n) {
            if (i % 2 == 0 && j % 2 != 0) {
                if (c[i] + minBalance >= 0 && c[j] - balance + minBalance >= 0) {
                    ans += minOf(c[i] + minBalance + (minBalance != 0L).toInt(), c[j] - balance + minBalance + (balance != minBalance).toInt())
                }
            }
            balance += if (j % 2 == 0) c[j] else -c[j]
            minBalance = minOf(minBalance, balance)
        }
    }
    println(ans)
}

fun Boolean.toInt() = if (this) 1 else 0