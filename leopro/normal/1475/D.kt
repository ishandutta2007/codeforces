fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val b = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val regular = (0 until n).filter { b[it] == 1 }.map { a[it] }.sortedDescending().toIntArray()
        val important = (0 until n).filter { b[it] == 2 }.map { a[it] }.sortedDescending().toIntArray()
        val prefixRegular = LongArray(regular.size + 1)
        for (i in regular.indices) prefixRegular[i + 1] = prefixRegular[i] + regular[i]
        val prefixImportant = LongArray(important.size + 1)
        for (i in important.indices) prefixImportant[i + 1] = prefixImportant[i] + important[i]
        var best = 3 * n
        for (regCnt in 0..regular.size) {
            val importantCount = prefixImportant.minAtLeast(m - prefixRegular[regCnt])
            best = minOf(best, regCnt + importantCount * 2)
        }
        println(if (best > 2 * n) -1 else best)
    }
}

fun LongArray.minAtLeast(v: Long): Int {
    var p = -1
    for (i in generateSequence(size.takeHighestOneBit()) { it / 2 }.takeWhile { it != 0 }) {
        if (p + i < size && this[p + i] < v) p += i
    }
    if (p == lastIndex) return 10_000_000
    return p + 1
}