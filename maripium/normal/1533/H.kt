private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val (N, M) = readInts()
    var board = MutableList(N) { String() }
    for (i in 0 until N) board[i] = readLn()
    var ans = LongArray(32) { 0L }
    for (mask in 0 until 32) {
        var nboard = Array(N) { BooleanArray(M) { false } }
        for (i in 0 until N) {
            for (j in 0 until M) {
                val c = board[i][j] - 'A'
                if ((mask and (1 shl c)) > 0) nboard[i][j] = true
            }
        }
        var H = IntArray(M) { 0 }
        for (i in 0 until N) {
            for (j in 0 until M) {
                if (nboard[i][j]) H[j] ++
                else H[j] = 0
            }
            var prv = IntArray(M) { -1 }
            var nxt = IntArray(M) { M }
            for (j in 0 until M) {
                prv[j] = j - 1
                while (prv[j] != -1 && H[j] < H[prv[j]]) prv[j] = prv[prv[j]]
            }
            for (j in (M-1).downTo(0)) {
                nxt[j] = j + 1
                while (nxt[j] != M && H[j] <= H[nxt[j]]) nxt[j] = nxt[nxt[j]]
            }
            for (j in 0 until M) {
                ans[mask] += 1L * H[j] * (j - prv[j]) * (nxt[j] - j)
            }
        }
    }
    for (i in 0 until 5) {
        for (j in 0 until 32) {
            if ((j and (1 shl i)) > 0) {
                ans[j] -= ans[j xor (1 shl i)]
            }
        }
    }
    var real_ans = LongArray(5) { 0 }
    for (i in 1 until 32) {
        real_ans[i.countOneBits() - 1] += ans[i]
    }   
    println(real_ans.joinToString(" "))
}