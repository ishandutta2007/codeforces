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
    var (n, k) = readInts()
    if(n < k) {
        println("NO")
    }
    else {
        var ar = ArrayList< Int >()
        var cur = 1
        var size = 0
        while(cur < 1e9) {
            ar.add(cur)
            cur = cur * 2
            size++
        }
        var ans = ArrayList< Int >()
        var size2 = 0
        for (i in size - 1 downTo 0) {
            while(n >= ar[i]) {
                ans.add(ar[i])
                n -= ar[i]
                size2++
            }
        }
        if(size2 > k) {
            println("NO")
        }
        else {
            println("YES")
            var indx = 0
            while(size2 < k) {
                if(ans[indx] > 1) {
                    ans[indx] /= 2
                    ans.add(ans[indx])
                    size2++
                }
                else {
                    indx++
                }
            }
            for (i in 0 until k) {
                print(ans[i])
                print(" ")
            }
        }
    }
}