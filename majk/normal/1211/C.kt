fun main(args: Array<String>) {
    val (N,K) = readLine()!!.split(" ").map { it.toInt() }
    val A = (0 until N).map { readLine()!!.split(" ").map { it.toLong() } }
    val lo = A.map { it[0] }.sum()
    val hi = A.map { it[1] }.sum()
    if (K < lo || K > hi) {
        println("-1")
    } else {
        var cost = A.map { it[0] * it[2] }.sum()
        val B = A.sortedBy { it[2] }
        var left = K - lo
        for (b in B) {
            if (b[1] - b[0] <= left) {
                left -= b[1] - b[0]
                cost += (b[1] - b[0]) * b[2]
            } else {
                cost += left * b[2]
                left = 0
            }
        }
        println(cost)
    }
}