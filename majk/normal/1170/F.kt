
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
    val (N, M, K) = readLine()!!.split(" ").map { it.toInt() }
    val A = readLine()!!.split(" ").map { it.toInt() }.sorted()
    val B = LongArray(N+1) { 0L }
    repeat(N) { B[it+1] = B[it] + A[it] }
    val Ans = (M-1 until N).map {
        val left = it-(M-1)
        val x = bsh(left, it) { y ->
            A[y].toLong() * (y-left+1) - (B[y+1] - B[left]) <= K
        }

        if (x < it - M/2) {
            val mid = Math.min(x, it - M/2)
            val toValue = bsh(A[mid], 1_000_000_000) { z -> z.toLong() * (mid-left+1) - (B[mid+1] - B[left]) <= K && A[mid+1] >= z }
            (mid - left + 1).toLong() * toValue - (B[mid + 1] - B[left]) + (B[it + 1] - B[mid + 1]) - toValue * (it - mid).toLong()
        } else {
            val mid = Math.min(x, it - M/2)
            val toValue = A[mid]
            (mid - left + 1).toLong() * toValue - (B[mid + 1] - B[left]) + (B[it + 1] - B[mid + 1]) - toValue * (it - mid).toLong()
        }

    }.min()
    println(Ans)
}