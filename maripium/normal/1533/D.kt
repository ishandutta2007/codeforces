private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val T = 1;
    for (t in 0 until T) {
        val (N, M) = readInts()
        var st = mutableSetOf<String>()
        for (i in 0 until N) {
            val str = readLn()
            st.add(str)
        }
        val Q = readInt()
        for (q in 0 until Q) {
            val str = readLn()
            var st0 = mutableSetOf<String>()
            for (i in 0 until M+1) {
                st0.add(str.substring(0, i) + str.substring(i + 1, M + 1))
            }
            var ans = 0
            for (s in st0) if (st.contains(s)) ans++
            println(ans)
        }
    }
}