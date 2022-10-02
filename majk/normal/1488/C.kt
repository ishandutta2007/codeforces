import java.lang.Integer.max
import java.lang.Integer.min

inline fun bsl(ll: Int,hh:Int, crossinline f:(Int)->(Boolean)): Int {
    var r = -1
    var m: Int
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
        val (N,A,B) = readLine()!!.split(" ").map { it.toInt() }
        val C=min(A,B)
        val D=max(A,B)

        val ans = bsl(0, N) {
            if (C - it > 1) false
            else if (D + it < N) false
            else {
                val maxK = max((it - (C-1))/2, it-2*(C-1))
                val maxL = max(it - 2*(N-D), (it - (N-D))/2)
                maxL + maxK >= D-C-1
            }
        }
        println(ans)

    }

}