fun main() {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    if (n < k) return println("NO")
    val cur = IntArray(30)
    cur[0] = n
    var sum = cur.sum()
    loop@while (sum > k) {
        for (j in cur.indices) {
            if (cur[j] > 1) {
                val d = minOf(cur[j] / 2, sum - k)
                cur[j] -= 2 * d
                cur[j + 1] += d
                sum -= d
                continue@loop
            }
        }
        return println("NO")
    }
    println("YES")
    for (i in cur.indices) repeat(cur[i]) {
        print("${1 shl i} ")
    }
}