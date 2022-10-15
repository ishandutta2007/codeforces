fun main() {
    fun isk4(x: Int) = x > 0 && (0..x).takeWhile { k -> k * k * k * k <= x }.last().let { k -> k * k * k * k == x }
    val multiply = 720720
    val new = IntArray(17)
    for (x in 1..16) {
        for (i in x until 1000_000 step x) {
            if (isk4(multiply - i)) {
                new[x] = i
                break
            }
        }
    }
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val a = Array(n) { readLine()!!.split(' ').map { it.toInt() }.toIntArray() }
    for (i in a.indices) {
        for (j in a[i].indices) {
            if ((i + j) % 2 == 0) a[i][j] = multiply else a[i][j] = new[a[i][j]]
        }
    }
    println(a.joinToString("\n") { it.joinToString(" ") })
}