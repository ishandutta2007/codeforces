fun run() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map{it.toInt()}.sorted()
    val b = readLine()!!.split(" ").map{it.toInt()}.sorted()
    val pref = (0 until n).scan(Int.MIN_VALUE){sum,idx->maxOf(sum,b[idx]-a[idx])}
    val suff = (0 until n).scan(Int.MIN_VALUE){sum,idx->maxOf(sum,b[n-idx]-a[n-idx-1])}
    val nq = readLine()!!.toInt()
    val q = readLine()!!.split(" ").map{it.toInt()}
    println(q.map{
        var idx = a.binarySearch(it)
        if(idx<0) idx=-idx-1
        maxOf(pref[idx],suff[n-idx],b[idx]-it)
    }.joinToString(" "))
}

fun main() {
    run()
}