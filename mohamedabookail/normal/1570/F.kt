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
    var (n, m) = readInts()
    var a = Array(n) {IntArray(m)}
    for (i in 0 until n) {
        a[i] = readInts().toIntArray()
    }
    var aa = ArrayList<Long>()
    var bb = ArrayList<Long>()
    var ok = 1
    for (i in 1 until n) {
        for (j in 1 until m) {
            var x = a[i][j] + a[i - 1][j - 1] + a[i][j - 1] + a[i - 1][j]
            if(x == 4) {
                aa.add(i * 1L)
                bb.add(j * 1L)
            }
        }
    }
    
    for (i in 1 until n) {
        for (j in 1 until m) {
            if(a[i][j] == 0 || a[i - 1][j - 1] == 0 || a[i][j - 1] == 0 || a[i - 1][j] == 0) {
                continue
            }
            a[i][j] = 2
            a[i - 1][j - 1] = 2
            a[i][j - 1] = 2
            a[i - 1][j] = 2
        }
    }
    
    for (i in 0 until n) {
        for (j in 0 until m) {
            if(a[i][j] == 1) {
                ok = 0
            }
        }
    }
    
    if(ok == 0) {
        println(-1)
    }
    else {
        println(aa.size)
        for (i in 0 until aa.size) {
            print(aa[i])
            print(' ')
            println(bb[i])
        }
    }
}