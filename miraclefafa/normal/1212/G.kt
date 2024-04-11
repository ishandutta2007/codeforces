import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var (n,l)=readInts()
    n+=1
    var x=IntArray(n)
    var b=IntArray(n)
    x[0]=0
    b[0]=0
    for (i in 1..n-1) {
        var (xx,bb)=readInts()
        x[i]=xx
        b[i]=bb
    }
    var vl: Double = 0.0
    var vr: Double = 1e+3
    var cost=Array(n,{DoubleArray(n)})
    for (i in 0..n-1)
        for (j in i+1..n-1)
            cost[i][j]=sqrt(abs(x[j]-x[i]-l).toDouble())
    var pre=IntArray(n)
    var dp=DoubleArray(n)
    for (rd in 0..100) {
        var md : Double = (vl+vr)/2
        dp.fill(0.0)
        pre.fill(0)
        dp[0]=-b[0]*md
        for (i in 1..n-1) {
            dp[i]=dp[0]+cost[0][i]
            pre[i]=0
            for (j in 1..i-1) {
                val cc=dp[j]+cost[j][i]
                if (cc<dp[i]) {
                    dp[i]=cc
                    pre[i]=j
                }
            }
            dp[i]-=b[i]*md
        }
        if (dp[n-1]<=0) vr=md
        else vl=md
    }
    var ans=ArrayList<Int>()
    var p=n-1
    while (p!=0) {
        ans.add(p)
        if (p==0) break
        p=pre[p]
    }
    ans.reverse()
    println(ans.map({it.toString()}).joinToString(" "))
}