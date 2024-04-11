import kotlin.math.abs

fun readInt() = readLine()!!.toInt() // single int
fun readStrings() = readLine()!!.split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readLine()!!.toInt()
    while (t > 0)
    {
        t--
       	val n = readInt()
       	val v = readInts()
       	var s = 0
       	var pz = 0
       	for(i in v)
            s+=i
        for(i in v.indices)
        {
            if(abs(v[i]*n - s) > abs(v[pz]*n -s))
            {
                pz=i
            }
        }
        println(pz+1)
    }
}