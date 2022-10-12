/**
*    author:  Mohamed Abo Okail
*    created: O1/1O/2O21
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
        var s = readLn()
        var a = -1
        var b = -1
        var ans = 0
        for (i in 0 until s.length) {
            if(s[i] == '1') {
                if(a == -1) a = i
                b = i
            }
        }
        for (i in a until b) {
            if(s[i] == '0') {
                ans++
            }
        }
        println(ans)
    }
}