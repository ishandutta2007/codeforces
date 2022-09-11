fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

fun calc(seq : MutableList<Int>) : Int {
    //println(seq.joinToString(" "))
    val n = seq.size
    val lds = mutableListOf<Int>()
    for(x in seq) {
        var lo = -1
        var hi = lds.size
        while(lo+1<hi) {
            val mi = lo+(hi-lo)/2
            if(x>=lds[mi]) hi=mi else lo=mi
        }
        if(hi==lds.size) lds.add(x) else lds[hi]=x
    }
    return lds.size
}

fun run() {
    val (n) = readInts()
    val a = readInts()
    val mx = a.maxOrNull()!!
    val pos = IntArray(mx+1){-1}
    for(i in n-1 downTo 0) if(pos[a[i]]==-1) pos[a[i]]=i
    var ret = 1
    for(type in 0..1) {
        val seq = mutableListOf<Int>()
        for(i in 0..n-1) if(pos[a[i]]!=-1&&pos[a[i]]!=i&&(type==0||pos[a[i]]!=i+1)) seq.add(pos[a[i]])
        val cur = 2 * calc(seq) + type
        ret = maxOf(ret,cur)
    }
    println(ret)
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}