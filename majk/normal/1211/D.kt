fun main(args: Array<String>) {
    val (N,A,B,K) = readLine()!!.split(" ").map{ it.toLong() }
    val R = readLine()!!.split(" ").map{ it.toLong() }.sorted()
    var ans = 0L
    for (RR in arrayOf(R, R.reversed())) {
        val M = mutableMapOf<Long, Long>()
        for (r in RR) M[r] = (M[r] ?: 0) + 1
        var cur = 0L
        val U = mutableMapOf<Long, Long>()
        for ((k,v) in M) {
            val vv = v - U.getOrDefault(k, 0)
            val ww = M.getOrDefault(k*K, 0) - U.getOrDefault(k*K, 0)
            val use = Math.min(vv / A, ww / B)
            cur += use
            U[k] = U.getOrDefault(k, 0) + use * A
            U[k*K] = U.getOrDefault(k*K, 0) + use * B
        }
        ans = Math.max(ans, cur)
    }
    println(ans)
}