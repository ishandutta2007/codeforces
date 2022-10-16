import kotlin.math.abs

fun readInt() = readLine()!!.toInt() // single int
fun readStrings() = readLine()!!.split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    //var t = readLine()!!.toInt()
    var t = 1
    while (t > 0)
    {
        t--
       	val n = readInt()
       	val v = readLine()
       	var ind = 0
       	var incr = 1
       	while(ind < n)
       	{
            print(v?.get(ind))
       	    ind+=incr
       	    incr+=1
       	}
       	println()
    }
}