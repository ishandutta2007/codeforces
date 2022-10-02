import java.lang.Integer.max
import java.util.Arrays

//inline fun bsl(ll: Int,hh:Int, crossinline f:(Int)->(Boolean)): Int {
//    var r = -1
//    var m: Int
//    var l = ll
//    var h = hh
//    while(l<=h){
//        m=(l+h)/2
//        if(f(m)){
//            h=m-1
//            r=m
//        }else{
//            l=m+1
//        }
//    }
//    return r
//}
//
//inline fun bsh(ll: Long,hh:Long, crossinline f:(Long)->(Boolean)): Long {
//    var r = -1L
//    var m: Long
//    var l = ll
//    var h = hh
//    while(l<=h){
//        m=(l+h)/2
//        if(f(m)){
//            l=m+1
//            r=m
//        }else{
//            h=m-1
//        }
//    }
//    return r
//}
//
//fun update(TT: LongArray, LT: LongArray, i: Int, L: Int, R: Int, l: Int, r: Int, v: Long) {
//    if (l >= R || r <= L) return
//    if (l <= L && r >= R) {
//        LT[i] = v
//        TT[i] = v * (R-L)
//        return
//    }
//
//    update(TT, LT, 2*i, L, (L+R)/2, l, r, v)
//    update(TT, LT, 2*i+1, (L+R)/2, R, l, r, v)
//    TT[i] = TT[2*i] + TT[2*i+1]
//}
//
//fun tot(TT: LongArray, LT: LongArray, i: Int, L: Int, R: Int, l: Int, r: Int): Long {
//    if (l >= R || r <= L) return 0L
//    if (LT[i] != 0L) return LT[i] * (min(R, r) - max(L, l))
//    if (l <= L && r >= R) return TT[i]
//
//    return tot(TT, LT, 2*i, L, (L+R)/2, l, r) + tot(TT, LT, 2*i+1, (L+R)/2, R, l, r)
//}


fun query(B: IntArray, i: Int, L: Int, R: Int, l: Int, r: Int): Int {
    return if (l >= R || r <= L) 0
    else if (l <= L && r >= R) B[i]
    else max(
        query(B, 2*i, L, (L+R)/2, l, r),
        query(B, 2*i+1, (L+R)/2, R, l, r)
    )
}

fun update(B: IntArray, i: Int, v: Int) {
    var j = i
    B[j] = v
    while (j > 1) {
        j /= 2
        B[j] = max(B[2*j], B[2*j+1])
    }
}

fun main(args: Array<String>) {
    val T=readLine()!!.toInt()
    repeat(T) {
        val N = readLine()!!.toInt()
        val A = readLine()!!.split(" ").map { it.toInt() }
        val F = mutableMapOf<Int, Int>()
        val S = mutableMapOf<Int, Int>()
        for (i in 0 until N) {
            val a = A[i]
            if (F.containsKey(a)) {
                S[a] = i
            } else {
                F[a] = i
            }
        }

        var MX = 1
        while (MX < N) MX *= 2
        val B = IntArray(2*MX) { 0 }

        val pairs = F.map { (v, l) -> l to S.getOrDefault(v, l) }.sortedBy { it.second }
        var ans = 0
        for ((a,b) in pairs) {
            val w = when {
                a == b -> 1
                a + 1 == b -> 2
                else -> 2 + max(1, query(B, 1, 0, MX, a, b))
            }
            ans = max(ans, w)
            update(B, a+MX, w)
        }
        println(ans)
    }

}