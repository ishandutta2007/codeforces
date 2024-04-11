 
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
        var (n, x) = readInts()
        var a = readInts()
        var cur = ArrayList<Int>()
        var ans = ArrayList<Int>()
        var cnt = 0
        var idx = 0
        var sum = 0
        for (i in n - 1 downTo 0) {
        sum += a[i]
            cnt++;
            cur.add(a[i])
            if(cnt % x == 0) {
                var sum = 0
                var flag = cnt / x
                var cntX = cnt - flag
                for (j in 1 until cnt) {
                    if(j >= cntX) {
                        sum += cur[j]
                    }
                }
                ans.add(sum)
                idx++
            }
        }
        ans.sort()
        if(x == 1) {
            println(sum)
        }
        else {
            println(ans[idx - 1])
        }
    }
}