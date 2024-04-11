fun main() {
    val (n, m, k) = readInts()
    val possibleSums = Array(n) { IntArray(m) }
    for (i in 0 until n) {
        val got = BooleanArray(k)
        possibleSums[i] = findPossibleSums(readIntArray(), m / 2).reversed().filter {
            weight -> !got[weight % k].also { got[weight % k] = true }
        }.toIntArray()
    }
    val allPossibleSums = IntArray(possibleSums.sumBy { it.max()!! } + 1) { n }
    allPossibleSums[0] = -1
    for (i in possibleSums.indices) {
        for (x in possibleSums[i]) {
            for (w in x until allPossibleSums.size) {
                if (allPossibleSums[w - x] < i && allPossibleSums[w] > i) allPossibleSums[w] = i
            }
        }
    }
    println(allPossibleSums.indices.filter { allPossibleSums[it] < n }.filter { it % k == 0 }.max()!!)
}

fun findPossibleSums(a: IntArray, maxOps: Int): IntArray {
    val result = IntArray(a.sum() + 1) { if (it == 0) 0 else a.size }
    for (x in a) {
        for (i in (x until result.size).reversed()) {
            result[i] = minOf(result[i], result[i - x] + 1)
        }
    }
    return result.indices.filter { result[it] <= maxOps }.toIntArray()
}

fun readLong() = readLine()!!.toLong()
fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()