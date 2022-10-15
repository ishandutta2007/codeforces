fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val count = List(n) { IntArray(n) { 0 } }
    val predictions = List(m) { readLine()!!.split(' ').map { it.toInt() - 1 }.also { (f, l) -> count[f][l]++ } }
    val rowSum = IntArray(n)
    val colSum = IntArray(n)
    for (i in 0 until n) {
        for (j in 0 until n) {
            rowSum[i] += count[i][j]
            colSum[j] += count[i][j]
        }
    }
    var ans = 0
    for (f in 0 until n) {
        for (l in 0 until n) {
            if (f == l) continue
            val best = count[f][l]
            val half = rowSum[f] + colSum[l] - 2 * best
            if ((f == predictions[0][0]) xor (l == predictions[0][1])) ans = maxOf(ans, best)
            if ((f != predictions[0][0]) && (l != predictions[0][1])) ans = maxOf(ans, best + half)
        }
    }
    println(ans + 1)
}