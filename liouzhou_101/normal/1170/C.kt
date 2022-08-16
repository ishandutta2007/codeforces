import java.util.*
import kotlin.math.*
 
private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readLong() = readString().toLong()
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints
 
val INF = 1e9

fun check(s: String, t: String): Boolean
{
    var n = s.length
    var m = t.length
    if (n < m) return false
    var i = 0
    for (c in t)
    {
        if (i == n) return false
        if (s[i] == c)
        {
            i ++
            continue
        }
        if (c == '-') return false
        if (i+1 < n && s[i+1] == '-')
            i += 2
        else
        	return false
    }
    return i == n
}
 
fun main(args: Array<String>)
{
    var T = readInt()
    for (tests in 1..T)
    {
        var s = readString()
        var t = readString()
        if (check(s, t))
        	println("YES")
        else
        	println("NO")
    }
}