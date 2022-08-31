private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>)
{
    var n = readInt()
    var s = readString()
    var F = HashMap<String, Int>()
    for (i in 0..n-2)
    {
        var x = s.substring(i, i+2)
        var y = F.get(x)
        if (y != null)
            F.set(x, y+1)
        else
        	F.put(x, 1)
    }
    var ret = Pair<Int, String>(0, "")
    val comparator = compareBy<Pair<Int, String>> { it.first }
    for ((x, y) in F)
    {
        ret = maxOf(ret, Pair<Int, String>(y, x), comparator)
    }
    println(ret.second)
}