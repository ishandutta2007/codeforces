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
    var n = readInt()
    var a = readInts().sorted()
    var ar = Array(150002) {IntArray(1)}
    var ans = 0
    for (i in 0 until n) {
        if(a[i] > 1 && ar[a[i] - 1][0] == 0) {
            ar[a[i] - 1][0] = 1
            ans++
        }
        else if(ar[a[i]][0] == 0) {
            ar[a[i]][0] = 1
            ans++
        }
        else if(ar[a[i] + 1][0] == 0){
            ar[a[i] + 1][0] = 1
            ans++
        }
    }
    println(ans)
}