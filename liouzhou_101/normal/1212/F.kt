import java.util.*
import kotlin.math.*

private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readLong() = readString().toLong()
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

var p = arrayOf<Long>()
var F = HashMap<Long, Long>()

fun solve(n: Long) : Long
{
    if (n == 0L) return 0
    if (F.containsKey(n)) return F.get(n)!!
    
    var len = 0
    var x = n
    while (x > 0)
    {
        x /= 10
        len ++
    }
    
    var ret = n
    if (abs(n-p[len-1]) < n) ret = minOf(ret, len+solve(abs(n-p[len-1])))
    if (abs(n-p[len]) < n) ret = minOf(ret, len+1+solve(abs(n-p[len])))
    
    F.put(n, ret)
    return ret
}

fun main(args: Array<String>)
{
    var cur = 0L
    for (i in 0..16)
    {
        cur = cur*10+1
        p += cur
    }
    var n = readLong()
    var ret = solve(n)
    println(ret)
}