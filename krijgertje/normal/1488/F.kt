fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

class Item(val idx: Int, val x: Int, val sum: Long) {
}

fun run() {
    val (n) = readInts()
    val a = readInts()
    val (nq) = readInts()
    val ql = IntArray(nq)
    val qr = IntArray(nq)
    for(i in 0..nq-1) { val (l,r) = readInts().map{it-1}; ql[i]=l; qr[i]=r; }
    val qans = LongArray(nq)
    val qbyr = Array(n){mutableListOf<Int>()}
    for(i in 0..nq-1) qbyr[qr[i]].add(i)
    val stack = mutableListOf<Item>()
    stack.add(Item(-1,Int.MAX_VALUE,0))
    for(i in 0..n-1) {
        while(stack.last().x<=a[i]) stack.removeLast()
        stack.add(Item(i,a[i],a[i].toLong()*(i-stack.last().idx)+stack.last().sum))
        for(id in qbyr[i]) {
            var lo=0
            var hi=stack.size-1
            while(lo+1<hi) {
                val mi=lo+(hi-lo)/2
                if(stack[mi].idx>=ql[id]) hi=mi else lo=mi
            }
            qans[id]=stack.last().sum-stack[hi].sum+stack[hi].x.toLong()*(stack[hi].idx-ql[id]+1)
        }
    }
    println(qans.joinToString(" "))
}

fun main() {
    run()
}