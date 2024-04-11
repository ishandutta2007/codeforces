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
        var s = readLn()
        var a = 0
        var b = 0
        var c = 0
        for (i in 0 until s.length) {
            if(s[i] == '=') a++
            if(s[i] == '>') b++
            if(s[i] == '<') c++
        }
        if(s.length == a) println('=')
        else if(s.length == a + b) println('>')
        else if(s.length == a + c) println('<')
        else println('?')
    }
}