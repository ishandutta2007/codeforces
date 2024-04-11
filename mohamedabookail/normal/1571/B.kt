/**
*    author:  Mohamed Abo Okail
*    created: O7/1O/2O21
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
        var n = readInt()
        var (a, b) = readLongs()
        var (c, d) = readLongs()
        var x = readInt()
        
        if(a == b && c == d) {
            println(x)    
        }
        else if(b == d) {
            println(b)
        }
        else {
            println(maxOf(b, d - (c - x)))
        }
    }
}