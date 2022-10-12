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
    val n = readInt()
    val a = readInts().sorted()
    
    var ans = 0
    for (i in 0 until n) {
        if(i % 2 == 1) {
            ans += a[i] - a[i - 1]
        }
    }
    println(ans)
}