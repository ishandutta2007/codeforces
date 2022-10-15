fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val c = List(n) { readLine()!!.split(' ').map { it.toInt() } }
    var cSum = m - c.filter { it[1] == 1 }.sumOf { it[0] }
    if (!solve(cSum, c.withIndex().filter { it.value[1] == 2 })) return println(-1)
    for (i in c.indices) {
        if (c[i][1] == 2) continue
        ans[i] = cSum
        cSum += c[i][0]
    }
    println(ans.slice(0 until n).map { it + 1 }.joinToString(" "))
}

fun solve(m: Int, c: List<IndexedValue<List<Int>>>): Boolean {
    val values = c.map { it.value[0] }.toIntArray()
    val sum = values.sum()
    if (sum > m) return false
    val up = (m + 1) / 2
    val down = (sum - (m / 2)).coerceAtLeast(0)
    val ok = IntArray(up + 1) { -2 }
    ok[0] = -1
    for (i in values.indices) {
        val x = values[i]
        for (cap in ok.indices.reversed()) {
            if (cap < x) break
            if (ok[cap - x] == -2 || ok[cap] != -2) continue
            ok[cap] = i
        }
    }
    if (ok.slice(down..up).all { it == -2 }) return false

    var ptr = (down..up).find { ok[it] != -2 }!!
    val even = BooleanArray(values.size)
    while (ptr > 0) {
        even[ok[ptr]] = true
        ptr -= values[ok[ptr]]
    }
    var cSum = 0
    for (i in values.indices) {
        if (!even[i]) continue
        ans[c[i].index] = 2 * cSum
        cSum += values[i]
    }
    cSum = 0
    for (i in values.indices) {
        if (even[i]) continue
        ans[c[i].index] = 2 * cSum + 1
        cSum += values[i]
    }
    return true
}

val ans = IntArray(5000)