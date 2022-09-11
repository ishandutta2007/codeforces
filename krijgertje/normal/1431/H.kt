import java.util.PriorityQueue

fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

class State(val want: Long, var opt: Int) {}

fun run() {
    val (na,nb,extra) = readInts()
    val a = readLongs()
    val b = readLongs()
    val c = Array(na, {readInts()})
    
    var ai = 0
    var bi = 0
    var have = 0L
    var opt = c[0][0]
    var states = mutableListOf<State>()
    while(true) {
        while(ai+1<na&&a[ai+1]<=have) {
            ++ai
            for(i in 0..bi) opt = maxOf(opt, c[ai][i])
        }
        while(bi+1<nb&&b[bi+1]<=have) {
            ++bi
            for(i in 0..ai) opt = maxOf(opt, c[i][bi])
        }
        if(ai==na-1&&bi==nb-1) break
        var want = minOf(if(ai+1<na) a[ai+1] else Long.MAX_VALUE,if(bi+1<nb) b[bi+1] else Long.MAX_VALUE)
        states.add(State(want,opt))
        have = want
    }
    if(states.size==0) { println(0); return }
    //for(state in states) println("want ${state.want} with ${state.opt}")
    
    var ret = Long.MAX_VALUE
    for(modstate in states) {
        modstate.opt += extra
        have = 0L
        var cur = 0L
        var opt = 0
        for(state in states) {
            opt = maxOf(opt,state.opt)
            if(have>=state.want) continue
            val t = (state.want-have+opt-1)/opt
            cur += t
            have += t*opt
        }
        modstate.opt -= extra
        ret = minOf(ret,cur)
    }
    println(ret)
}

fun main() {
    run()
}