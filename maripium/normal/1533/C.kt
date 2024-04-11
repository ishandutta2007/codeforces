private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val T = readInt()
    for (t in 0 until T) {
        val (N, K) = readInts()
        val S = readLn()
        var alive = BooleanArray(N) { true }
        var cur = 0
        var ans = 0
        while (true) {
            var has = false
            for (i in 0 until N) if ((S[i] == '1') and alive[i]) has = true
            if (!has) break
            ans++
            alive[cur] = false
            if (ans == N) break
            for (k in 0 until K) {
                cur = (cur + 1) % N
                while (!alive[cur]) cur = (cur + 1) % N
            }
        } 
        println(ans)
    }
}