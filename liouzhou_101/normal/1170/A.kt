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
    var T = readInt()
    for (i in 1..T)
    {
        var (x, y) = readInts()
        var a = minOf(x, y)-1
        var b = x-a
        var c = y-a
        println("$a $b $c")
    }
}