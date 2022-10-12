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
     var a = readInt()
     var b = readInt()
     var k1 = readInt()
     var k2 = readInt()
     var n = readInt()
     if(k1 > k2) {
        a = b.also { b = a }
        k1 = k2.also { k2 = k1 }
     }
     
     var mn = maxOf(0, n - (a * (k1 - 1) + b * (k2 - 1)))
     
     var x = n / k1
     var y = minOf(a, x)
     n -= y * k1
     var mx = y + minOf(n / k2, b)
     
     print(mn)
     print(' ')
     println(mx)
}