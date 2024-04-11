import java.io.*
import java.math.BigDecimal
import java.math.BigInteger
import java.util.Arrays
import java.util.Comparator
import java.util.Random
import java.util.StringTokenizer

internal var br = BufferedReader(InputStreamReader(System.`in`))
internal var st: StringTokenizer? = null
internal var out = PrintWriter(System.out)

@Throws(IOException::class)
internal fun next(): String {
    while (st == null || !st!!.hasMoreTokens()) {
        st = StringTokenizer(br.readLine())
    }
    return st!!.nextToken()
}

@Throws(IOException::class)
internal fun nextInt(): Int {
    return Integer.parseInt(next())
}

@Throws(IOException::class)
internal fun nextLong(): Long {
    return java.lang.Long.parseLong(next())
}

@Throws(IOException::class)
internal fun solve() {
    val n=nextInt()
    val a=nextInt()
    val b=nextInt()
    val k=nextInt()
    val M=1000000
    var cnt=IntArray(M+1)
    for (i in 0..n-1) {
        val c=nextInt()
        cnt[c]+=1
    }
    var ans=0
    if (a>=b) {
        for (i in 1..M/k) {
            while (cnt[i]>=a) {
                cnt[i]-=a
                var pc=i*k
                if (cnt[pc]>=b) {
                    cnt[pc]-=b
                    ans+=1
                }
            }
        }
    } else {
        for (i in M/k downTo 1) {
            while (cnt[i]>=a&&cnt[i*k]>=b) {
                cnt[i]-=a
                cnt[i*k]-=b
                ans+=1
            }
        }
    }
    out.println(ans)
}

fun main(args: Array<String>) {
    solve()
    out.close()
}