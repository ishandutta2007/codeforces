import java.lang.Integer.max
import java.lang.Integer.min

inline fun bsl(ll: Long,hh:Long, crossinline f:(Long)->(Boolean)): Long {
    var r = -1L
    var m: Long
    var l = ll
    var h = hh
    while(l<=h){
        m=(l+h)/2
        if(f(m)){
            h=m-1
            r=m
        }else{
            l=m+1
        }
    }
    return r
}

inline fun bsh(ll: Long,hh:Long, crossinline f:(Long)->(Boolean)): Long {
    var r = -1L
    var m: Long
    var l = ll
    var h = hh
    while(l<=h){
        m=(l+h)/2
        if(f(m)){
            l=m+1
            r=m
        }else{
            h=m-1
        }
    }
    return r
}

fun main(args: Array<String>) {
    val T=readLine()!!.toInt()
    repeat(T) {
        val (N,S) = readLine()!!.split(" ").map { it.toLong() }
        val ans = bsh(1L, S) {
            var z = it
            var tot = 0L
            for (i in 1..N) {
                tot += z
                z = (z+1)/2
                if (tot > S) break
                if (z == 1L) {
                    tot += N-i
                    break
                }
            }
            tot <= S
        }
        println(ans)
    }

}

/*
val T=readLine()!!.toInt()
    repeat(T) {
        val (N,A,B) = readLine()!!.split(" ").map { it.toInt() }
        val C=min(A,B)
        val D=max(A,B)

    }
 */