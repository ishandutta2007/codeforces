
import java.lang.Integer.min
import java.lang.Long.max

fun main() {
    val (N, K) = readLine()!!.split(' ').map { it.toInt() }
    val A = readLine()!!.split(' ').map { it.toInt() }.sorted()
    val P = IntArray(N+1) { 0 }
    for (i in 0 until N) P[i+1] = P[i] + A[i]
    val DP = Array(N+1) { LongArray(K+1) { 0 } }

    for (i in 0 until N) {
        for (j in 0..K) {
            DP[i+1][j] = max(DP[i+1][j], DP[i][j])
            for (k in 1..min(K-j, (N-i)/2)) {
                DP[i+2*k][j+k] = max(DP[i+2*k][j+k], DP[i][j] + (P[i+2*k]-P[i+k])-(P[i+k]-P[i]))
            }
        }
    }
    println(DP[N][K])
}