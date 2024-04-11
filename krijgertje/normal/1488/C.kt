fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }

fun run() {
    val (n,_x,_y) = readInts()
    val x = minOf(_x - 1,_y - 1)
    val y = n - 1 - maxOf(_x - 1,_y - 1)
    var lo = -1;
    var hi = 2 * n
    fun can(t : Int) : Boolean {
        if(t<x||t<y) return false
        val l = maxOf(t-x,x+(t-x)/2)
        var r = n-1-maxOf((t-y),y+(t-y)/2)
        return l+1>=r
    }
    while(lo + 1 < hi) {
        val mi = lo + (hi - lo)/2
        if(can(mi)) hi = mi else lo = mi
    }
    println(hi)
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}