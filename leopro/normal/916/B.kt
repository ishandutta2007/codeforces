fun main() {
    val (n, kTemp) = readLine()!!.split(' ').map { it.toLong() }
    val k = kTemp.toInt()
    val bitSize = (0 until Int.MAX_VALUE).find { (1L shl it) > n }!!
    if (n.countOneBits() > k) return println("No")
    println("Yes")
    val y = run {
        var l = -30
        var r = bitSize
        while (r - l > 1) {
            val m = (l + r) / 2
            var cnt = 0L
            for (bit in 0 until bitSize) {
                if ((n and (1L shl bit)) == 0L) continue
                if (bit <= m) cnt++ else cnt += 1L shl (bit - m)
            }
            if (cnt <= k) r = m else l = m
        }
        r
    }
    val ans = mutableListOf<Int>()
    for (bit in bitSize downTo 0) {
        if ((n and (1L shl bit)) == 0L) continue
        if (bit <= y) {
            ans.add(bit)
        } else {
            repeat(1 shl (bit - y)) {
                ans.add(y)
            }
        }
    }
    while (ans.size < k) {
        val x = ans.removeLast()
        ans.add(x - 1)
        ans.add(x - 1)
    }
    println(ans.joinToString(" "))
}