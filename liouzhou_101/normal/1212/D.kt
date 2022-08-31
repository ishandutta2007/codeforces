import java.util.*

private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readLong() = readString().toLong()
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

fun main(args: Array<String>)
{
    var n = readInt()
    var a = readLongs().toLongArray()
    var b = Array<Triple<Int, Int, Long>>(0, {i -> Triple(0, 0, 0)})
    for (tx in a)
    {
        var x = tx
        var s = 0
        var t = 0
        while (x%2 == 0L)
        {
            s ++
            x /= 2
        }
        while (x%3 == 0L)
        {
            t ++
            x /= 3
        }
        b += Triple(s, t, tx)
    }
    b.sortWith(compareBy({it.first}, {-it.second}))
    for ((x, y, z) in b)
    	print("$z ")
}