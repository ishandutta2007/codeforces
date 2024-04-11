fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

fun run() {
    val (n,sum) = readLongs()
    var lo = 1L
    var hi = sum+1
    fun can(x : Long) : Boolean {
        var rem = sum
        var nxt = x
        var cnt = n
        while(true) {
            if(cnt==0L) return true
            if(nxt==1L) return rem>=cnt
            if(rem<nxt) return false
            rem -= nxt
            --cnt
            nxt = maxOf(1,(nxt+1)/2)
        }
    }
    while(lo + 1 < hi) {
        val mi = lo + (hi - lo)/2
        if(can(mi)) lo = mi else hi = mi
    }
    println(lo)
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}