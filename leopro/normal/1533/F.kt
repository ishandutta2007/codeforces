fun main() {
    val s = readLine()!!
    val zeros = IntArray(s.length + 1)
    val ones = IntArray(s.length + 1)
    for (i in s.indices) {
        if (s[i] == '0') zeros[i + 1] = 1 else ones[i + 1] = 1
        zeros[i + 1] += zeros[i]
        ones[i + 1] += ones[i]
    }
    fun zeros(l: Int, r: Int) = zeros[r] - zeros[l]
    fun ones(l: Int, r: Int) = ones[r] - ones[l]
    fun ok(l: Int, r: Int, k: Int) = zeros(l, r) <= k || ones(l, r) <= k
    val ans = mutableListOf<Int>()
    for (k in 1..s.length) {
        var i = 0
        var cnt = 0
        while (!ok(i, s.length, k)) {
            var l = i + k
            var r = s.length
            while (r - l > 1) {
                val m = (l + r) / 2
                if (ok(i, m, k)) l = m else r = m
            }
            i = l
            cnt++
        }
        ans.add(cnt + 1)
    }
    println(ans.joinToString(" "))
}