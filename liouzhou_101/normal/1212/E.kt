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
    var c = arrayOf<Triple<Int, Int, Int>>()
    for (i in 0..n-1)
    {
        var (a, b) = readInts()
        c += Triple(a, b, i)
    }
   	c.sortWith(compareBy({it.first}))
    
    var k = readInt()
    var a = readInts().toTypedArray()
    var b = Array<Pair<Int, Int>>(k, {x -> Pair(a[x], x)})
    b.sortWith(compareBy({it.first}))
    
    var earn = 0
    var ret = arrayOf<Pair<Int, Int>>()
    
    var j = 0
    var H = PriorityQueue<Pair<Int, Int>>(compareBy({-it.first}))
    for (i in 0..k-1)
    {
        while (j < n && c[j].first <= b[i].first)
        {
            H.add(Pair(c[j].second, c[j].third))
            j ++
        }
        if (H.size > 0)
        {
            var (cur, id) = H.poll()
            earn += cur
            ret += Pair(id, b[i].second)
        }
    }
    
    println("${ret.size} $earn")
    for ((x, y) in ret)
    {
        println("${x+1} ${y+1}")
    }
}