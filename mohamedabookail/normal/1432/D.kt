
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
        var (n, a, b) = readLongs()
        var cnt = 0
        var idx = 0
        var str = "abcdefghijklmnopqrstuvwxyz"
        for (i in 0 until n) {
            print(str[idx])
            cnt++;
            if(cnt < b) idx++
            if(cnt >= a) {
                cnt = 0
                idx = 0
            }
        }
        println()
    }
}