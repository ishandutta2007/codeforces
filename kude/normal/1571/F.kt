private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    val (n, m) = readInts()
    val ord_2 = ArrayList<Int>()
    val k = IntArray(n)
    val t = IntArray(n)
    for(i in 0 until n) {
        val (ki, ti) = readInts()
        k[i] = ki
        t[i] = ti
        if (ti == 2) {
            ord_2 += i
        }
    }
    val dp = Array(m + 1) { false }
    dp[0] = true
    val pre = Array(m + 1) { -1 }
    var sm = 0
    for(i in ord_2) {
        sm += k[i]
        for(j in m - k[i] downTo 0) if (dp[j] && !dp[j + k[i]]) {
            dp[j + k[i]] = true
            pre[j + k[i]] = i
        }
    }
    var p = minOf(sm / 2, m)
    while(!dp[p]) p--
    val q = sm - p
    val cnt = if (p == q) sm else 2 * q - 1
    var sm_rest = 0
    for(i in 0 until n) {
        if (t[i] == 1) sm_rest += k[i]
    }
    if (cnt + sm_rest > m) {
        println(-1)
        return
    }


    val ans = IntArray(n)
    var ptr = cnt
    for(i in 0 until n) if (t[i] == 1) {
        ans[i] = ptr
        ptr += k[i]
    }

    val odds = Array(n) { false }
    ptr = p
    while(ptr != 0) {
        odds[pre[ptr]] = true
        ptr -= k[pre[ptr]]
    }
    var ptr_odd = 1
    var ptr_even = 0
    for(i in 0 until n) if (t[i] == 2) {
        if (odds[i]) {
            ans[i] = ptr_odd
            ptr_odd += 2 * k[i]
        } else {
            ans[i] = ptr_even
            ptr_even += 2 * k[i]
        }
    }
    println(ans.map{it + 1}.joinToString(" "))
}

fun main() {
    val tt = 1
    repeat(tt) { solve() }
}