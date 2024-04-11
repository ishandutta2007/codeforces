object C544 {
    def main(args: Array[String]) {
      val Array(n, m, b, mod) = readLine.split(" ").map(_.toInt)
      val A = readLine.split(" ").map(_.toInt)
      val dp = Array.ofDim[Int](2, m + 10, b + 10)
      dp(0)(0)(0) = 1
      for (i <- 1 to n) {
        for (j <- 0 to m) {
          for (k <- 0 to b) {
            dp(i & 1)(j)(k) = dp(1 - (i & 1))(j)(k)
            if (j > 0 && k >= A(i - 1)) {
              dp(i & 1)(j)(k) += (dp(i & 1)(j - 1)(k - A(i - 1)))
            }
            dp(i & 1)(j)(k) %= mod
          }
        }
      }
      var ans: Int = 0
      for (i <- 0 to b) {
        ans += dp(n & 1)(m)(i)
        ans %= mod
      }
      println(ans)
    }
  }