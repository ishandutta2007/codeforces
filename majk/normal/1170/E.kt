
inline fun bsh(ll: Int,hh:Int, crossinline f:(Int)->(Boolean)): Int {
    var r = -1
    var m: Int
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

fun main() {
    val (N, M) = readLine()!!.split(" ").map { it.toInt() }
    val A = readLine()!!.split(" ").map { it.toInt() }
    val B = IntArray(N+1) { 0 }
    repeat(N) { B[it+1] = B[it] + A[it] }
    val Q = readLine()!!.toInt()
    repeat(Q) {
        val C = readLine()!!.split(" ").map { it.toInt() }.drop(1).plus(M+1)
        var prev = 0
        var last = 0
        C.forEach {x ->
            prev = bsh(0, N) { B[it] - B[prev] < x - last }
            last = x
        }
        println(if (prev == N) "YES" else "NO")
    }
}