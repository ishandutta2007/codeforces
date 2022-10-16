 
 
fun readInt() = readLine()!!.toInt() // single int
fun readStrings() = readLine()!!.split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
 
val N = 200000

var fv = Array(N+1) {i -> 0}

fun main() {
    //var t = readLine()!!.toInt()
    var t = 1
    while (t > 0)
    {
        t--
       	val n = readInt()
       	val vi = readInts()
       	val v = vi.toTypedArray()
       	v.sort()
        for(i in v)
            ++fv[i]
        var ok = true
        for(i in v)
            if(fv[i] > 2)
                ok = false
        if(ok == false)
        {
            println("NO")
            continue
        }
        
        println("YES")
        var incr = mutableListOf<Int>()
        var decr = mutableListOf<Int>()
        for(i in v.indices)
            if(i == 0 || v[i] != v[i-1])
                incr.add(v[i])
        for(i in v.indices.reversed())
            if(i != 0 && v[i] == v[i-1])
                decr.add(v[i])
        println(incr.count())
        for(i in incr)
            print("$i ")
        println()
        println(decr.count())
        for(i in decr)
            print("$i ")
        println()
    }
}