
import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var t = readInt()
    while(t -- > 0) {
        var n = readInt()
        var a = readStrings().map { it.toLong() }.sorted()
        var ans = ArrayList<Long>()
        for (i in 0 until n) {
            ans.add(a[i] * (n - i))
        }
        ans.sort()
        println(ans[n - 1])
    }
}