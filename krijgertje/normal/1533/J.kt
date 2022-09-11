import java.util.ArrayDeque

fun run() {
    val n = readLine()!!.toInt()
    val pawn = Array(500000) {mutableListOf<Int>()}
    repeat(n) { val (x,y)=readLine()!!.split(" ").map{it.toInt()-1}; pawn[y].add(x) }
    //println(pawn.indices.filter{it->pawn[it].size>0}.map{it->""+it+"="+pawn[it]}.joinToString(" "))
    for(y in pawn.indices) pawn[y].sort()
    
    fun process(a:MutableList<Int>,b:MutableList<Int>) {
        if(a.isEmpty()&&b.isEmpty()) return
        //print("$a $b")
        val brem = ArrayDeque<Int>()
        val arem = ArrayDeque<Int>()
        while(a.isNotEmpty()) {
            val aval=a.removeLast()
            while(b.isNotEmpty()&&b.last()>aval) brem.addFirst(b.removeLast())
            if(brem.isNotEmpty()) brem.removeFirst(); else arem.addFirst(aval)
        }
        while(b.isNotEmpty()) brem.addFirst(b.removeLast())
        a.addAll(arem)
        b.addAll(brem)
        //println(" -> $a $b")
    }
    
    var ret=n
    for(par in 0..1) {
        var last=mutableListOf<Int>()
        for(y in pawn.indices) {
            val copy=pawn[y].toMutableList()
            if(y%2==par) {
                process(copy,last)
                ret-=pawn[y].size-copy.size
                last=copy
            } else {
                process(last,copy)
                ret-=pawn[y].size-copy.size
                last=copy
            }
        }
    }
    println(ret)
}

fun main() {
    run()
}