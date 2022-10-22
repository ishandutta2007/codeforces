fun main() {
    val (n, m, d) = readLine()!!.split(" ").map{it.toInt()}
    val c = readLine()!!.split(" ").map{it.toInt()}.toIntArray()
    val s = c.sum()
    val gapTotal = n - s
    val q = gapTotal / (m + 1)
    var r = gapTotal % (m + 1)
    val gaps = ArrayList<Int>(m + 1)
    repeat(m + 1) {
        val g = q + if (r > 0) 1 else 0
        if (r > 0) --r
        gaps.add(g)
    }
    if (gaps.max()!! >= d) {
        println("NO")
        return
    }
    val ans = ArrayList<Int>(n)
    repeat(m) {
        repeat(gaps[it]) {
            ans.add(0)
        }
        val i = it + 1
        repeat(c[it]) {
            ans.add(i)
        }
    }
    repeat(gaps[m]) {
        ans.add(0)
    }
    println("YES")
    for(i in ans.indices) {
        print(ans[i])
        print(if (i == ans.lastIndex) '\n' else ' ')
    }
}