import java.util.*
import kotlin.math.*
 
private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readLong() = readString().toLong()
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints
 
val INF = 1e9
 
fun main(args: Array<String>)
{
    var n = readInt()
    var a = readInts().toTypedArray()
    var x = 0
    var y = 0
    var ans = 0
    for (v in a)
    {
        if (x > v && y > v) ans ++
        if (v > x)
        {
            y = x
            x = v
        }
        else
        	y = maxOf(y, v)
    }
    println(ans)
}