import java.util.PriorityQueue

fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

fun run() {
    val (n,lim,sz) = readInts()
    val a = readLongs().toLongArray()
    var lo = -1L
    var hi = a.sum()
    while(lo + 1 < hi) {
        val mi = lo + (hi - lo) / 2
        val q  = PriorityQueue<Long>()
        var at = 0
        var cnt = 0
        var sum = 0L
        var need = 0
        while(true) {
            if(sum > mi) {
                --cnt
                sum -= -q.remove()
                ++need
            } else if(cnt < sz && at < n) {
                ++cnt
                sum += a[at]
                q.add(-a[at])
                ++at
            } else if(cnt >= sz) {
                cnt = 0
                sum = 0
                q.clear()
            } else {
                break
            }
        }
        if(need<=lim) hi = mi; else lo = mi
    }
    println(hi)
}

fun main() {
    run()
}