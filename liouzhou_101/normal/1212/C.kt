private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
fun main(args: Array<String>)
{
    var (n, k) = readInts()
    var a = readInts().toTypedArray()
    a.sort()
    var ret = -1
    if (k == 0)
    {
        ret = a[0]-1
        if (ret < 1) ret = -1
    }
    else
    {
    	ret = a[k-1]
    	if (k < n && a[k] == a[k-1])
   		{
        	ret = -1
    	}
    }
    println(ret)
}