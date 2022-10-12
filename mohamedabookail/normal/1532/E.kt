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
    val n = readInt()
    val a = readInts()
    val ans = ArrayList<Long>()
    val mp = IntArray(10000005)
    var sum = 0L
    for (i in 0 until n) {
        sum += a[i]
        mp[a[i]] += 1
    }
    for (i in 0 until n) {
        sum -= a[i]
        if(sum / 2 * 2 == sum && sum / 2 <= 1000000) {
            if(a[i] == (sum / 2).toInt()) {
                if(mp[a[i]] >= 2) {
                    ans.add(i + 1 * 1L)
                }
            }
            else {
                if(mp[(sum / 2).toInt()] >= 1) {
                    ans.add(i + 1 * 1L)
                }
            }
        }
        sum += a[i]
    }
    println(ans.size)
    for(i in 0 until ans.size) {
        print(ans[i])
        print(' ')
        
    }
}