
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
    var tt = readInt()
    for (qq in 0 until tt) {
        var (n, k1, k2) = readInts()
        var s = readLn()
        var ans = 0
        var flag = 0
        for (i in 1 until n) {
            if(flag > 0) {
                if(i == n - 1 && s[i] == '1') {
                    ans = ans + k1
                }
                flag --
                continue
            }
            if(s[i] == '1' && s[i - 1] == '1') {
                if(k2 <= k1 * 2) ans = ans + k2
                else ans = ans + k1 * 2
                flag ++
            }
            else if(s[i - 1] == '1') {
                ans = ans + k1
            }
            else if(i == n - 1 && s[i] == '1') {
                ans = ans + k1
            }
        }
        if(n == 1 && s[0] == '1') println(k1)
        else println(ans)
    }
}