/**
*    author:  Mohamed Abo Okail
*    created: 22/O2/2O22
**/
 
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
        val n = readInt()
        val a = readInts()
        var ans = -1
        for (i in 1 until n - 1) {
            if(a[i] != a[i - 1] && a[i] != a[i + 1]) {
                ans = i + 1
                break
            }
        }
        if(ans == -1) {
            if(a[0] == a[1]) ans = n
            if(a[1] == a[n - 1]) ans = 1
        }
        println(ans)
    }
}