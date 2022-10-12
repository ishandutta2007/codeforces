
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
        var (n, k) = readLongs()
        var n1 = 1
        var n2 = k
        var n3 = k * k
        var n4 = k * k * k
        var sum = n1 + n2 + n3 + n4
        var flag = n / sum
        print(n1 * flag)
        print(' ')
        print(n2 * flag)
        print(' ')
        print(n3 * flag)
        print(' ')
        print(n4 * flag)
        println()
    }
}