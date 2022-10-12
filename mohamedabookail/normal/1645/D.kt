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
    var ok = 1
    for (i in 1 until n - 1) {
        if(a[i] == a[i - 1] && a[i] == a[i + 1]) {
            ok = 0
            break
        }
    }
    if(ok == 1) {
        println("YES")
        var ar = Array(200001) {IntArray(1)}
        var cnt = 0
        ar[a[0]][0] = 1
        for (i in 1 until n) {
            if(a[i] == a[i - 1]) {
                cnt++
            }
            ar[a[i]][0]++
        }
        println(cnt)
        var ar1 = Array(200001) {IntArray(1)}
        for (i in 0 until n) {
            if(ar1[a[i]][0] == 0 && ar[a[i]][0] == 2) {
                ar1[a[i]][0] = 1
                print(a[i])
                print(" ")
            }
        }
        println()
        println(n - cnt)
        var ar2 = Array(200001) {IntArray(1)}
        for (i in n - 1 downTo 0) {
            if(ar2[a[i]][0] == 0) {
                ar2[a[i]][0] = 1
                print(a[i])
                print(" ")
            }
        }
    }
    else {
        println("NO")
    }
}