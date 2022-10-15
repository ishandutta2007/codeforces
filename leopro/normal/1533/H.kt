data class Cell(val i: Int, val j: Int)

fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val matrix = List(n) { readLine()!! }
    val k = 5
    val cnt = LongArray(1 shl k)
    for (mask in 0 until (1 shl k)) {
        val allowed = BooleanArray(k) { mask and (1 shl it) != 0 }
        val boo = matrix.map { it.map { allowed[it - 'A'] }.toBooleanArray() }
        val belowOne = List(n) { IntArray(m) }
        for (j in 0 until m) {
            for (i in n - 1 downTo 0) {
                when {
                    !boo[i][j] -> belowOne[i][j] = i
                    i + 1 == n -> belowOne[i][j] = n
                    else -> belowOne[i][j] = belowOne[i + 1][j]
                }
            }
        }
        for (i in 0 until n) {
            val belowOnes = mutableListOf(Cell(0, m))
            var sum = 0
            for (j in m - 1 downTo 0) {
                var curJ = j + 1
                while (belowOne[i][j] < belowOnes.last().i) {
                    val last = belowOnes.last()
                    val prev = belowOnes[belowOnes.lastIndex - 1]
                    sum -= (prev.j - curJ) * (last.i - i)
                    curJ = prev.j
                    belowOnes.removeLast()
                }
                sum += (belowOnes.last().j - j) * (belowOne[i][j] - i)
                belowOnes.add(Cell(belowOne[i][j], j))
                cnt[mask] = cnt[mask] + sum
            }
        }
    }
    val ans = LongArray(1 shl k)
    for (mask in 0 until (1 shl k)) {
        for (subMask in 0 until (1 shl k)) {
            if (mask.inv() and subMask != 0) continue
            ans[mask] += if ((mask xor subMask).countOneBits() % 2 != 0) -cnt[subMask] else cnt[subMask]
        }
    }
    val res = LongArray(k + 1)
    for (mask in 0 until (1 shl k)) res[mask.countOneBits()] += ans[mask]
    println(res.drop(1).joinToString(" "))
}