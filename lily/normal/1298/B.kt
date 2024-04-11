fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readLong() = readLn().toLong() // single long
fun readDouble() = readLn().toDouble() // single double
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
fun readLongs() = readStrings().map { it.toLong() } // list of longs
fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val n = readInt()
    val a = readInts()
    val vis = BooleanArray(1001)
    val ans = mutableListOf<Int>()
    for (i in n - 1 downTo 0) {
        if (!vis[a[i]]) {
            ans.add(a[i])
            vis[a[i]] = true;
        }
    }
    println(ans.size)
    ans.reverse()
    for (i in ans) {
        print("${i} ")
    }
}