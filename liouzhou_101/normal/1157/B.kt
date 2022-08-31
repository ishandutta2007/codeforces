private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>)
{
    var n = readInt()
    var a = readString()
    var f = readInts()
    var i = a.indexOfFirst { x -> f[x-'1'] > x-'0' }
        .takeIf { it >= 0 } ?: a.length
    var j = a.withIndex().indexOfFirst { (j, x) -> j > i && f[x-'1'] < x-'0' }
        .takeIf { it >= 0 } ?: a.length
    var ret = a.substring(0, i) +
    	a.substring(i, j).map { x -> '0'+f[x-'1'] }.joinToString("") +
    	a.substring(j)
    println(ret)
}