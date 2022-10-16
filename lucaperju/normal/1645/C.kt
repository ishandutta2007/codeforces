

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
       	val vi = readInts()
       	val v = vi.toTypedArray()
       	var s = 0
       	v.sort()
       	for(i in v.indices step 2)
       	    s+=v[i+1] - v[i]
       	println(s)
    }
}