/**
*    author:  Mohamed Abo Okail
*    created: O4/1O/2O21
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
    var n = readInt()
    var x = n
    var ans = 1
    if(n < 10) {
        println(9)
        return
    }
    while(true) {
        n++
        while(n % 10 == 0) {
            n /= 10
        }
        if(n < 10) {
            ans += 9
            break
        }
        ans++
    }
    println(ans)
}