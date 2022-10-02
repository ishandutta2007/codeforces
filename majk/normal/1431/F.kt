import java.util.*

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

fun main() {
    val (N, K, X) = readLine()!!.split(' ').map { it.toInt() }
    val A = readLine()!!.split(' ').map { it.toInt() }

    fun isOk(mx: Long): Boolean {
        var i = 0
        var rem = 0
        while (i < N) {
            val ts = TreeSet<Long>()
            var sum = 0L
            while (i < N && ts.size < X) {
                ts.add(A[i]*100000L+i)
                sum += A[i]
                i += 1
            }

            while (sum > mx) {
                val ll = ts.last()
                ts.remove(ll)
                sum -= ll / 100000
                rem += 1
                if (i < N) {
                    ts.add(100000L*A[i]+i)
                    sum += A[i]
                    i += 1
                }
            }
        }
        return rem <= K
    }

    val z = bsl(0L, 100000000000L) { isOk(it) }
    println(z)
}