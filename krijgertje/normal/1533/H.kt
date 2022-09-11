import java.util.ArrayDeque

fun run() {
    val (h,w) = readLine()!!.split(" ").map{it.toInt()}
    val g = (0 until h).map{readLine()!!.map{it-'A'}}

    val ans = LongArray(6){0L}
    for(mask in 0 until (1 shl 5)) {
        val up = Array(w){0}
        val q = Array(w+1){0}
        for(x in 0 until h) {
            for(y in 0 until w) if((mask shr g[x][y]) and 1!=0) ++up[y]; else up[y]=0
            var nq=0
            q[nq++]=-1
            var area = 0
            var sum = 0
            for(y in 0 until w) {
                while(q[nq-1]!=-1&&up[y]<=up[q[nq-1]]) {
                    val py=q[--nq]
                    area-=up[py]*(py-q[nq-1])
                }
                area+=up[y]*(y-q[nq-1])
                sum+=area
                q[nq++]=y
            }
            ans[mask.countOneBits()]=ans[mask.countOneBits()]+sum
        }
    }
    fun choose(n: Int, k: Int) : Int { var ret = 1; for(i in 0 until k) ret=ret*(n-i)/(i+1); return ret }
    for(i in ans.indices) for(j in 0 until i) ans[i]-=ans[j]*choose(5-j,i-j)
    println(ans.drop(1).joinToString(" "))
}

fun main() {
    run()
}