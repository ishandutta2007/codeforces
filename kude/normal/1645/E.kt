fun main() {
    val (n, k) = readLine()!!.split(" ").let { Pair(it[0].toInt(), it[1].toInt()) }
    if (k < n.countOneBits() || k > n) {
        println("NO")
        return
    }
    val d = IntArray(30)
    for (i in 0 until 30) {
        d[i] = n shr i and 1
    }
    var rest = k - n.countOneBits()
    var i = 29
    while (rest > 0) {
        while (d[i] == 0) i--
        d[i]--
        d[i - 1] += 2
        rest--
    }
    val ans = IntArray(k)
    var ptr = 0
    for (i in 0 until 30) {
        ans.fill(1 shl i, ptr, ptr + d[i])
        ptr += d[i]
    }
    println("YES")
    println(ans.joinToString(" "))
}