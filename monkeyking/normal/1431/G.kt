import java.util.Arrays
import java.util.Scanner
  internal var s = Scanner(System.`in`)
  internal var n:Int = 0
  internal var k:Int = 0
  internal var a = IntArray(1)
  internal var sum = IntArray(1)
  internal fun getSum(i:Int, k:Int):Int {
    return (sum[i + k - 1] - sum[i - 1]) - (sum[i - 1] - sum[i - k - 1])
  }
  fun main(args:Array<String>) {
    // TODO Auto-generated method stub
    n = s.nextInt()
    k = s.nextInt()
    a = IntArray(n + 1)
    sum = IntArray(n + 1)
    sum[0] = 0
    a[0] = 0
    for (i in 1..n)
    {
      a[i] = s.nextInt()
    }
    Arrays.sort(a)
    for (i in 1..n)
    {
      sum[i] = sum[i - 1] + a[i]
    }
    val dp = Array<IntArray>(405, {IntArray(405)})
    for (i in 0..n)
    {
      for (j in 0..k)
      {
        dp[i][j] = -1000000000
      }
    }
    dp[0][0] = 0
    for (i in 0 until n)
    {
      for (j in 0..k)
      {
        if (dp[i + 1][j] < dp[i][j])
        {
          dp[i + 1][j] = dp[i][j]
        }
        for (use in 1..k - j)
        {
          if (i + use * 2 > n) continue
          if (dp[i + use * 2][j + use] < dp[i][j] + getSum(i + use + 1, use))
          {
            dp[i + use * 2][j + use] = dp[i][j] + getSum(i + use + 1, use)
          }
        }
      }
    }
    println(dp[n][k])
  }