/**
*    author:  Mohamed Abo Okail
*    created: 22/O6/2O21
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
        var (a, b) = readLongs()
        var ch = 'a'
        var s = ""
        for (i in 0 until b) {
            s += ch
            ch++
        }
        var indx = 0
        for (i in 0 until a) {
            print(s[indx])
            indx++
            if(indx >= b) {
                indx = 0
            }
        }
        println()
    }
}