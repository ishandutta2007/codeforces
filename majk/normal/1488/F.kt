import java.lang.Integer.max
import java.lang.Integer.min
import java.util.Arrays

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

fun update(TT: LongArray, LT: LongArray, i: Int, L: Int, R: Int, l: Int, r: Int, v: Long) {
    if (l >= R || r <= L) return
    if (l <= L && r >= R) {
        LT[i] = v
        TT[i] = v * (R-L)
        return
    }

    update(TT, LT, 2*i, L, (L+R)/2, l, r, v)
    update(TT, LT, 2*i+1, (L+R)/2, R, l, r, v)
    TT[i] = TT[2*i] + TT[2*i+1]
}

fun tot(TT: LongArray, LT: LongArray, i: Int, L: Int, R: Int, l: Int, r: Int): Long {
    if (l >= R || r <= L) return 0L
    if (LT[i] != 0L) return LT[i] * (min(R, r) - max(L, l))
    if (l <= L && r >= R) return TT[i]

    return tot(TT, LT, 2*i, L, (L+R)/2, l, r) + tot(TT, LT, 2*i+1, (L+R)/2, R, l, r)
}

fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    val C = readLine()!!.split(" ").map { it.toInt() }
    val Q = readLine()!!.toInt()
    val QQ = (0 until Q).map { it ->
        val (L,R) = readLine()!!.split(" ").map { it.toInt() }
        it to ((L-1 to R-1))
    }.sortedBy { it.second.second }

    val BN = 262144
    val TT = LongArray(2*BN) { 0 }
    val LT = LongArray(2*BN) { 0 }

    fun update(l: Int, r: Int, v: Long) {
        update(TT, LT, 1, 0, BN, l, r, v)
    }

    fun tot(l: Int, r: Int) = tot(TT, LT, 1, 0, BN, l, r)

    val S = mutableListOf<Pair<Int, Int>>()
    val Ans = LongArray(Q) { 0 }
    var j = 0
    for (i in 0 until N) {
        S.add(C[i] to i)
        while (S.size >= 2 && S[S.size-1].first >= S[S.size-2].first) {
            S[S.size-2] = S[S.size-1].first to S[S.size-2].second
            S.removeLast()
        }
        update(S.last().second, i+1, C[i].toLong())
        while (j < Q && QQ[j].second.second == i) {
            val L = QQ[j].second.first
            val idx = QQ[j].first

            Ans[idx] = tot(L, i+1)
            j += 1
        }
    }


    println(Ans.joinToString(separator = " ", prefix = "", postfix = "") { it.toString() })
}


//fun main(args: Array<String>) {
//    val T=readLine()!!.toInt()
//    repeat(T) {
//        val N = readLine()!!.toInt()
//        val A = readLine()!!.split(" ").map { it.toInt() }
//        val F = mutableMapOf<Int, Int>()
//        val S = mutableMapOf<Int, Int>()
//        for (i in 0 until N) {
//            val a = A[i]
//            if (F.containsKey(a)) {
//                S[a] = i
//            } else {
//                F[a] = i
//            }
//        }
//
//        val pairs = F.map { (v, l) -> (S.getOrDefault(v, l) - l) to v }
//        println(ans)
//    }
//
//}