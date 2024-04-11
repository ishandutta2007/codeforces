import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    val (n, m) = readInts()
    val s = mutableSetOf<String>()
    repeat(n) {
        s.add(readLn())
    }
    val q = readInt()
    repeat(q) {
        val t = readLn().toCharArray()
        val st = mutableSetOf<String>()
        for(i in 0 until m + 1) {
            val x = ArrayList<Char>()
            for(j in 0 until m + 1) {
                if (j != i) x.add(t[j])
            }
            st.add(x.joinToString(""))
        }
        var ans = 0
        for(ti in st) {
            if (s.contains(ti)) ans++
        }
        println(ans)
    }
}