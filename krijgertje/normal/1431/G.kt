import java.util.PriorityQueue

fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

fun run() {
    val (n,turns) = readInts()
    val a = readInts().toIntArray()
    a.sort()
    val sum = IntArray(n+1)
    sum[0] = 0
    for(i in 0 until n) sum[i+1]=sum[i]+a[i]
    val dp = Array(turns+1, {IntArray(n+1){0}})
    for(i in 0..turns) for(j in 0 until n) {
        dp[i][j+1] = maxOf(dp[i][j+1],dp[i][j])
        var sz = 1
        while(i+sz<=turns && j+2*sz<=n) {
            val cur = dp[i][j]+(sum[j+2*sz]-sum[j+sz])-(sum[j+sz]-sum[j])
            dp[i+sz][j+2*sz]=maxOf(dp[i+sz][j+2*sz],cur)
            ++sz
        }
    }
    println(dp[turns][n])
}

fun main() {
    run()
}